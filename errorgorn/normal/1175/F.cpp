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

const ll INC=1e6;

struct node{
	int s,e,m;
	ll val=0,lazy=0,num;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		num=e-s+1;
		
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
			num=(l->val==val?l->num:0)+(r->val==val?r->num:0);
		}
	}
	
	ll query(int i,int j){
		propo();
		
		if (s==i && e==j){
			if (val==0) return num;
			else return 0;
		}
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
}*root=new node(0,300005);

int n;
int arr[300005];
int p[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(p,-1,sizeof(p));
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	vector<int> mx={-1};
	
	ll ans=0;
	
	rep(x,0,n){
		while (mx.back()!=-1 && arr[mx.back()]<arr[x]){
			int temp=mx.back();
			mx.pop_back();
			root->update(mx.back()+1,temp,arr[x]-arr[temp]);
		}
		root->update(x,x,arr[x]);
		mx.push_back(x);
		
		if (p[arr[x]]!=-1) root->update(0,p[arr[x]],INC);
		p[arr[x]]=x;
		
		root->update(0,x,-1);
		
		ans+=root->query(0,x);
	}
	
	cout<<ans<<endl;
}