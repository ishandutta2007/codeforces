//
//

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

int n,m,q;
vector<ii> edge;

int last[200005];

struct UFDS{
	int p[200005];
	int par[200005]; //parity to touch parent
	int s[200005];
	
	vector<ii> op;
	
	UFDS(){
		rep(x,0,200005){
			p[x]=x;
			par[x]=0;
			s[x]=1;
		}
	}
	
	ii parent(int i){
		int parity=0;
		
		while (p[i]!=i){
			parity^=par[i];
			i=p[i];
		}
		
		return ii(i,parity);
	}
	
	bool unions(int i,int j){
		ii temp;
		int pi,pj;
		temp=parent(i);
		i=temp.fi,pi=temp.se;
		temp=parent(j);
		j=temp.fi,pj=temp.se;
		
		if (i==j){
			return (pi==pj);
		}
		else{
			if (s[i]<s[j]) swap(i,j);
			
			p[j]=i;
			par[j]=pi^pj^1;
			s[i]+=s[j];
			op.push_back(ii(i,j));
		}
		
		return false;
	}
	
	void rollback(int ss){
		while (sz(op)>ss){
			int i=op.back().fi,j=op.back().se;
			op.pop_back();
			
			p[j]=j;
			s[i]-=s[j];
		}
	}
} ufds=UFDS();

void dnc(int l1,int l2,int r1,int r2){
	if (l2<l1) return;
	
	int l=(l1+l2)>>1;
	
	int save=sz(ufds.op);
	
	rep(x,l1,l){
		if (ufds.unions(edge[x].fi,edge[x].se)){
			rep(y,x+1,l2+1) last[y]=m;
			ufds.rollback(save);
			dnc(l1,x,r1,r2);
			return;
		}
	}
	
	int save2=sz(ufds.op);
	
	//all from l1 to l merged
	rep(x,r2+1,r1){
		if (x==l || ufds.unions(edge[x].fi,edge[x].se)){
			//cout<<l<<" "<<x<<endl;
			
			last[l]=x;
			ufds.rollback(save2);
			if (ufds.unions(edge[l].fi,edge[l].se)){
				rep(y,l+1,l2+1) last[y]=m;
			}
			else{
				dnc(l+1,l2,x,r2);
			}
			ufds.rollback(save);
			rep(y,r2+1,x+1) ufds.unions(edge[y].fi,edge[y].se);
			dnc(l1,l-1,r1,x);
			ufds.rollback(save);
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>q;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		edge.push_back(ii(a,b));
	}
	
	dnc(0,m-1,0,m-1);
	
	//rep(x,0,m) cout<<last[x]<<" "; cout<<endl;
	
	while (q--){
		cin>>a>>b;
		
		if (b<=last[a-1]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}