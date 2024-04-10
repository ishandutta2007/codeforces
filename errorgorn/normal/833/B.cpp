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
			
			val=max(l->val,r->val);
		}
	}
	
	ll query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
}*root[55];


int n,k;
int arr[35005];
map<int,int> occ;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,0,55) {
		root[x]=new node(0,35005);
	}
	
	cin>>n>>k;
	rep(x,1,n+1){
		cin>>arr[x];
		occ[arr[x]]=-1;	
	}
	
	rep(x,1,n+1){
		rep(y,1,k){
			root[y+1]->update(x,x,root[y]->query(0,x-1));
		}
		rep(y,1,k+1){
			root[y]->update(occ[arr[x]]+1,x,1);
		}
		
		occ[arr[x]]=x;
		
		//cout<<root[1]->query(x,x)<<" "<<root[2]->query(x,x)<<endl;
	}
	
	cout<<root[k]->query(0,n)<<endl;
}