/*













*/

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
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
	int val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int k){
		if (s==e) val^=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val=__gcd(l->val,r->val);
		}
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return __gcd(l->query(i,m),r->query(m+1,j));
	}
}*root=new node(0,300005);

struct node2{
	int s,e,m;
	int val=0;
	node2 *l,*r;
	
	node2 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i,int k){
		if (s==e) val^=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val=min(l->val,r->val);
		}
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
}*root2=new node2(0,300005);

int n,q;
int arr[300005];
vector<int> ans;

bool can(int i){
	rep(x,0,n-i){
		if (root->query(x,x+i)==root2->query(x,x+i)) return true;
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n){
		cin>>arr[x];
		root->update(x,arr[x]);	
		root2->update(x,arr[x]);	
	}
	
	int lo=0,hi=n,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (can(mi)) lo=mi;
		else hi=mi;
	}
	
	rep(x,0,n-lo){
		if (root->query(x,x+lo)==root2->query(x,x+lo)) ans.push_back(x);
	}
	
	cout<<sz(ans)<<" "<<lo<<endl;
	for (auto &it:ans) cout<<it+1<<" ";
}