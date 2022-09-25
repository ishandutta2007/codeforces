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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n;
int arr[200005];

struct node{
	int s,e,m;
	int val=-1e9;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val=max(l->val,r->val);
		}
	}
	
	void update(int i,int j){
		if (s==e){
			val=max(val,j);
		}
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			
			val=max(l->val,r->val);
		}
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,200005);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	rep(x,1,n+1) arr[x]=x-arr[x];
	
	//rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
	
	root->update(1,0);
	
	vector<int> id;
	rep(x,1,n+1) if (arr[x]>=0 && x-arr[x]>=0) id.pub(x);
	sort(all(id),[](int i,int j){
		if (arr[i]!=arr[j]) return arr[i]<arr[j];
		else return i<j;
	});
	
	for (auto &x:id){
		root->update(x-arr[x]+1,root->query(0,x-arr[x])+1);
	}
	
	cout<<root->val<<endl;
}