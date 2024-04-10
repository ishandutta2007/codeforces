/*













*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct node{
	int s,e,m;
	ll val=0,lazy=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy){
			val+=lazy;
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			lazy=0;
		}
	}
	
	void update(int i,int j,ll k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=min(l->val,r->val);
		}
	}
	
	ll query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
}*fwd=new node(0,50005),*bwd=new node(0,50005);

string s;
ii cost[50005];
vector<int> proc;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	
	rep(x,0,sz(s)){
		if (s[x]=='?'){
			proc.push_back(x);
			fwd->update(x,50005,1);
			bwd->update(0,x,1);
		}
		else if (s[x]=='('){
			fwd->update(x,50005,1);
			bwd->update(0,x,-1);
		}
		else{
			fwd->update(x,50005,-1);
			bwd->update(0,x,1);
		}
	}
	
	for (auto &it:proc){
		cin>>cost[it].fi>>cost[it].se;
	}
	
	sort(all(proc),[](int i,int j){
		return abs(cost[i].fi-cost[i].se)>abs(cost[j].fi-cost[j].se);
	});
	
	ll ans=0;
	
	for (auto &it:proc){
		if (cost[it].fi<cost[it].se){ //try left bracket
			if (bwd->query(0,it)>=2){
				bwd->update(0,it,-2);
				s[it]='(';
				ans+=cost[it].fi;
			}
			else{
				fwd->update(it,50005,-2);
				s[it]=')';
				ans+=cost[it].se;
			}
		}
		else{
			if (fwd->query(it,50005)>=2){
				fwd->update(it,50005,-2);
				s[it]=')';
				ans+=cost[it].se;
			}
			else{
				bwd->update(0,it,-2);
				s[it]='(';
				ans+=cost[it].fi;
			}
		}
	}
	
	if (bwd->query(0,0)!=0 || fwd->query(0,sz(s)-1)<0) cout<<"-1"<<endl;
	else cout<<ans<<endl<<s<<endl;
}