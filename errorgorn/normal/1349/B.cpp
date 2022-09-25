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

const int INF=1e9;

struct node{
	int s,e,m;
	ll val=0, lazy=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	ll propo(){
		if (lazy==0) return val;
		else{
			val+=lazy;
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			lazy=0;
			
			return val;
		}
	}
	
	void update(int i,int j,ll k){
		//cerr<<i<<" "<<j<<" "<<k<<endl;
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			val=max(l->propo(),r->propo());
		}
	}
	
	ll query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
}*even,*odd;

int n,k;
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while(TC--){
		cin>>n>>k;
		rep(x,0,n) cin>>arr[x];
		
		bool exists=false;
		rep(x,0,n) if (arr[x]==k) exists=true;
		
		if (!exists){
			cout<<"no"<<endl;
			continue;
		}
		
		even=new node(0,n/2+5);
		odd=new node(0,n/2+5);
		int lim=n/2+5;
		
		bool can=(n==1);
		
		rep(x,n,0){
			if (arr[x]<k){
				if (x%2==0){
					even->update(x/2,lim,-1);
					odd->update(x/2,lim,-1);
				}
				else{
					even->update(x/2+1,lim,-1);
					odd->update(x/2,lim,-1);
				}
			}
			
			if (x%2==0) even->update(x/2,n/2,1);
			else odd->update(x/2,(n-1)/2,1);
			
			//cout<<even->query((x+2)/2,lim)<<" "<<odd->query((x+1)/2,lim)<<endl;
			if (even->query((x+2)/2,lim)>0 || odd->query((x+1)/2,lim)>0) can=true;
		}
		
		if (can) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}