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

const int MOD=998244353;

int n,q;
int arr[500005];

struct dat{
	ll a,b,c,d; //[l,r], [l,r-1], [l+1,r], [l+1,r-1];
	
	dat(int i){ //single value
		a=i+1,b=1,c=1,d=0;
	}
	
	void merge(dat &i, dat &j,int m){
		ll temp=arr[m]*10+arr[m+1];
		if (10<=temp && temp<=18) temp=19-temp;
		else temp=0;
		
		a=(i.a*j.a+i.b*temp%MOD*j.c)%MOD;
		b=(i.a*j.b+i.b*temp%MOD*j.d)%MOD;
		c=(i.c*j.a+i.d*temp%MOD*j.c)%MOD;
		d=(i.c*j.b+i.d*temp%MOD*j.d)%MOD;
	}
};

struct node{
	int s,e,m;
	dat val=dat(0);
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val.merge(l->val,r->val,m);
		}
		else{
			val=dat(arr[s]);
		}
	}
	
	void update(int i){
		if (s==e) val=dat(arr[s]);
		else{
			if (i<=m) l->update(i);
			else r->update(i);
			
			val.merge(l->val,r->val,m);
		}
	}
} *root;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	
	string s;
	cin>>s;
	
	rep(x,0,sz(s)) arr[x+1]=s[x]-'0';
	root=new node(1,n);
	
	int a,b;
	while (q--){
		cin>>a>>b;
		
		arr[a]=b;
		root->update(a);
		
		cout<<root->val.a<<endl;
	}
	
}