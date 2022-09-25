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

struct node{
	int s,e,m;
	ll val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j){
		if (s==e) val=j;
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			
			val=min(l->val,r->val);
		}
	}
	
	ll query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
}*root=new node(0,100005);

int n;
ll arr[100005];
ll pre[100005];
ll pos[80];
ll previous[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,1,n+1){
		cin>>arr[x];
		pre[x]=pre[x-1]+arr[x];
		
		root->update(x,pre[x]);
	}
	
	ll ans=0;
	
	rep(x,1,n+1){	
		pos[arr[x]+30]=x;
		rep(y,arr[x]+31,61) previous[x]=max(previous[x],pos[y]);
		
		//cout<<previous[x]<<endl;
		
		int curr=x;
		
		while (curr!=0){
			ans=max(ans,pre[x]-root->query(previous[curr],curr-1)-arr[curr]);	
			
			//cout<<pre[x]-root->query(previous[curr],curr-1)-arr[curr]<<endl;
			
			curr=previous[curr];
		}	
	}
	
	cout<<ans<<endl;
}