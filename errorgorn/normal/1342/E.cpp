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

const int MOD=998244353;

ll factorial(int i){
	if (i==1) return 1;
	else return (factorial(i-1))*i%MOD;
}

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


int n,k;

int main(){
	cin>>n>>k;
	
	if (k==0){
		cout<<factorial(n);
	}
	else if (k<n){
		//we need to fit n balls into n-k buckets
		
		k=n-k;
		
		ll ans=qexp(k,n,MOD);
		
		ll combi=1;
		
		rep(x,1,k+1){
			combi=(combi*(k+1-x))%MOD;
			combi=(combi*qexp(x,MOD-2,MOD))%MOD;
			
			//cout<<combi<<endl;
			
			if (x%2==0) ans=(ans+qexp(k-x,n,MOD)*combi)%MOD;
			else ans=((ans-qexp(k-x,n,MOD)*combi)%MOD+MOD)%MOD;
		}
		
		rep(x,1,k+1){
			ans=(ans*(n+1-x))%MOD;
			ans=(ans*qexp(x,MOD-2,MOD))%MOD;
		}
		
		cout<<(ans*2)%MOD<<endl;
	}
	else{
		cout<<0<<endl;
	}
}