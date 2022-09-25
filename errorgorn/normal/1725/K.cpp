//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int INF=2e9;

int n,q;
ii upd[400005];
int ans[400005];
vector<iii> qu[400005];

struct node{
	int s,e,m;
	vector<ii> in;
	vector<int> out;
	node *l,*r;
	
	int has(int i){
		auto it=ub(all(in),ii(i,INF));
		if (it!=in.begin() && i<=(*prev(it)).se) return it-in.begin()-1;
		else return -1;
	}
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			//merge shit
			
			//first merge all stuff that gets joined in the second half
			rep(x,0,sz(r->in)){
				int L,R;
				
				auto it=lb(all(l->out),r->in[x].fi);
				int idx=it-l->out.begin()-1;
				L=min(max(l->in[idx].se+1,r->in[x].fi),l->in[idx+1].fi);
				
				it=ub(all(l->out),r->in[x].se);
				idx=it-l->out.begin();
				R=max(min(l->in[idx].fi-1,r->in[x].se),l->in[idx-1].se);
				
				if (L<=R){
					//cout<<"add: "<<L<<" "<<R<<" "<<r->in[x].fi<<" "<<r->in[x].se<<endl;
					in.pub({L,R});
					out.pub(r->out[x]);
				}
			}
			
			//now merge stuff from first half that isnt in second half
			rep(x,0,sz(l->in)){
				if (r->has(l->out[x])!=-1) continue;
				
				in.pub(l->in[x]);
				out.pub(l->out[x]);
			}
		}
		else{
			int m=upd[s].fi+upd[s].se>>1;
			
			
			in.pub({-INF,-INF}); in.pub({upd[s].fi-1,m}); in.pub({m+1,upd[s].se+1}); in.pub({INF,INF});
			out.pub(-INF); out.pub(upd[s].fi-1); out.pub(upd[s].se+1); out.pub({INF});
		}
		
		sort(all(in));
		sort(all(out));
		
		// cout<<"hi: "<<s<<" "<<e<<endl;
		// for (auto [a,b]:in) cout<<a<<"_"<<b<<" "; cout<<endl;
		// for (auto it:out) cout<<it<<" "; cout<<endl;
	}
	
	int query(int i,int j,int val){
		//cerr<<s<<" "<<e<<" "<<i<<" "<<j<<endl;
		if (s==i && e==j){
			int temp=has(val);
			if (temp==-1) return val;
			else return out[temp];
		}
		else{
			if (j<=m) return l->query(i,j,val);
			else if (m<i) return r->query(i,j,val);
			else return r->query(m+1,j,l->query(i,m,val));
		}
	}
} *root;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int AIDX=0,UIDX=0;
	int a,b;
	rep(x,1,n+1){
		cin>>a;
		qu[x].pub({UIDX,a,-1});
	}
	
	cin>>q;
	rep(x,0,q){
		cin>>a;
		
		if (a==1){
			cin>>a>>b;
			qu[a].pub({UIDX,b,-1});
		}
		else if (a==2){
			cin>>a;
			qu[a].pub({UIDX,-1,AIDX++});
		}
		else{
			cin>>a>>b;
			upd[UIDX++]={a,b};
		}
	}
	
	upd[UIDX]={2,3};
	root=new node(0,UIDX);
	
	rep(x,1,n+1){
		int pp=0;
		rep(y,0,sz(qu[x])){
			if (get<2>(qu[x][y])==-1) pp=y;
			else{
				int val=get<1>(qu[x][pp]);
				int l=get<0>(qu[x][pp]),r=get<0>(qu[x][y])-1;
				
				//cout<<get<2>(qu[x][y])<<" "<<val<<" "<<l<<" "<<r<<endl;
				//cerr<<l<<" "<<r<<" "<<UIDX<<endl;
				if (l<=r) val=root->query(l,r,val);
				
				ans[get<2>(qu[x][y])]=val;
			}
		}
	}
	
	rep(x,0,AIDX) cout<<ans[x]<<endl;
}