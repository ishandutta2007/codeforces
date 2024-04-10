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

const int MOD=1000000007;
 
long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}
 
ll fix(ll i){
	while (i<0) i+=MOD;
	while (MOD<=i) i-=MOD;
	
	return i;
}

int n,p;
int arr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>p;
		rep(x,0,n) cin>>arr[x];
		
		if (p==1){
			cout<<n%2<<endl;
			continue;
		}
		
		sort(arr,arr+n);
		reverse(arr,arr+n);
		
		ll ans=0;
		ll curr=0;
		
		rep(x,0,n){
			if (curr==0){
				curr++;
				ans=fix(ans+qexp(p,arr[x],MOD));
			}
			else{
				curr--;
				ans=fix(ans-qexp(p,arr[x],MOD));
			}
			
			if (curr) rep(y,0,arr[x+1]-arr[x]){
				if (curr>1000000) break;
				curr*=p;
			}
		}
		
		cout<<ans<<endl;
	}
	
}