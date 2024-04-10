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

const int MODV=1000000007;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

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
	
	void update(int i,ll j){
		val=(val+j)%MODV;
		if (s==e) return;
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
		}
	}
	
	ll query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return (l->query(i,m)+r->query(m+1,j))%MODV;
	}
} *root=new node(0,200005);

int MOD;

ll n,k; 
ll arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k>>MOD;
	rep(x,1,n+1) cin>>arr[x];
	
	ll tot=0;
	rep(x,1,n+1) tot=(tot+arr[x])%MOD;
	
	//cout<<tot<<endl;
	
	if (tot==0){
		ll ans=0;
		ll curr=0;
		
		rep(x,1,n+1){
			ans=(ans+root->query(curr,curr)+MODV)%MODV;
			root->update(curr,1);
			
			curr=(curr+arr[x])%MOD;
		}
		
		cout<<(ans*2%MODV*k%MODV*k+n*k%MODV*(k-1)+1)%MODV<<endl;
	}
	else{
		ll totd=qexp(MOD-tot,MOD-2,MOD);
		//cout<<totd<<endl;
		
		ll ans=0;
		
		ll curr=0;
		rep(x,1,n+1){
			//cout<<"d: "<<curr<<" "<<(curr*totd%MOD)<<endl;
			root->update(curr*totd%MOD,1);
			
			curr=(curr+arr[x])%MOD;
		}
		
		curr=0;
		rep(x,1,n+1){
			ll l=curr*totd%MOD,r=l+k;
			ll temp=root->val;
			for (ll x=(1<<17);x;x>>=1){
				if (l+x*MOD<=r){
					ans=(ans+x*temp)%MODV;
					l+=x*MOD;
				}
			}
			l%=MOD,r%=MOD;
			
			if (l<=r) ans=(ans+root->query(l,r))%MODV;
			else ans=(ans+root->query(l,MOD-1)+root->query(0,r))%MODV;
			
			curr=(curr+arr[x])%MOD;
		}
		
		root=new node(0,200005);
		rep(x,1,n+1){
			root->update(curr,1);
			ans=(ans-root->query(curr,curr)+MODV)%MODV;
			
			curr=(curr+arr[x])%MOD;
		}
		
		root=new node(0,200005);
		rep(x,1,n+1){
			root->update(curr,1);
			ans=(ans-root->query((curr+k*tot)%MOD,(curr+k*tot)%MOD)+MODV)%MODV;
			
			curr=(curr+arr[x])%MOD;
		}
		
		ans=ans*k%MODV;
		if (tot*k%MOD==0) ans=(ans+1)%MODV;
		cout<<ans<<endl;
	}
}