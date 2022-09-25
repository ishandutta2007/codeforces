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

struct node{
	int s,e,m;
	ll mx=0,mn=0,lazy=0;
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
			mx+=lazy;
			mn+=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			
			lazy=0;
		}
	}
	
	void update(int i,int j,int k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			
			mx=max(l->mx,r->mx);
			mn=min(l->mn,r->mn);
		}
	}
	
	ll qmx(int i,int j){
		propo();
		
		if (s==i && e==j) return mx;
		else if (j<=m) return l->qmx(i,j);
		else if (m<i) return r->qmx(i,j);
		else return max(l->qmx(i,m),r->qmx(m+1,j));
	}
	
	ll qmn(int i,int j){
		propo();
		
		if (s==i && e==j) return mn;
		else if (j<=m) return l->qmn(i,j);
		else if (m<i) return r->qmn(i,j);
		else return min(l->qmn(i,m),r->qmn(m+1,j));
	}
} *root=new node(0,200005);

int n,p;
int arr[100005];
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>p;
	
	int mx=-1;
	rep(x,0,n){
		cin>>arr[x];
		mx=max(mx,arr[x]);	
	}
	
	mx-=n-1;
	
	rep(x,0,n){
		//cout<<"debug: "<<arr[x]-mx<<endl;
		root->update(max(0,arr[x]-mx),200005,1);
	}
	
	rep(x,0,200005) root->update(x,200005,-1);
	
	rep(x,0,n){
		root->update(x,200005,1);
		
		//cout<<x<<endl;
		//cout<<root->qmn(x,x+n-1)<<" "<<root->qmx(x,x+n-1)<<endl;
		
		if (root->qmn(x,x+n-1)>=1 && root->qmx(x,x+n-1)<p) ans.push_back(mx+x);
	}
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it<<" ";
}