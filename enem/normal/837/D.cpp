#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define pqb   priority_queue<long long int>
#define eb emplace_back
#define eps 1e-6
#define vll vector<long long int>
#define pqs   priority_queue<int,vll,greater<long long int> >
#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)

using namespace std;
typedef long long int ll;
//-------------------------------------Mod_operations------------------------------------------
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
const ll inf = 2e18;
const int infi=2e9;
ll mod(ll x){   return (x%M);}
ll mod_minus(ll a, ll b){ ll ans= (mod(a)-mod(b)); if(ans<0) ans=mod(ans+M); return ans;}
ll mod_mul(ll a,ll b){  return mod(mod(a)*mod(b));}
ll mod_add(ll a,ll b){ return mod(mod(a)+mod(b));}
ll power(ll a,ll n){  if(n==0) return 1;  else if(n==1) return a;  ll R=power(a,n/2)%M;  if(n%2==0) {  return mod(mod_mul(R,R)); }   else { return mod(mod_mul(mod_mul(R,a),mod(R)));  }}

ll mod_div(ll a,ll b){// only if M is prime
    ll ans=mod(a);
    ll b1=power(b,M-2);
     ans= mod(mod_mul(ans,b1));
     return ans;
}

ll fact_mod(ll n){
    vll fact(n+1);
    fact[0]=1;
    for(ll i=1;i<n+1;i++){
        fact[i]=mod_mul(fact[i-1],i);
    }
    return fact[n];
}
ll nCr_mod(ll n , ll r){
    return mod( mod_mul(mod_mul(fact_mod(n),mod(fact_mod(power(r,M-2))) ), 
                                       mod(power(fact_mod(n-r),M-2))   )   );
}
pair<ll,ll> Egcd(ll a,ll b)
{
  if(b==0)
    return make_pair(1,0);
  pair<ll,ll> t=Egcd(b,a%b);
  return make_pair(t.se,t.fi-(a/b)*t.se);
}
//-------------------------------------------------------------------------------------------------
vector<pair<int,int>> a;
vector<vector<int>> dp[2];
void solve() {
	int n,k0;
	ll u;
	cin>>n>>k0;
	for(int i=0; i<n; i++) {
		cin>>u;
		int te2=0,te5=0;
		while(u%2==0) {
			u/=2;
			te2++;
		}
		while(u%5==0) {
			u/=5;
			te5++;
		}
		a.pb({te2,te5});
	}
 
	for(int i=0; i<=1; i++)
	{
		dp[i].resize(n+1);
		for(int j=0; j<=n; j++) {
			dp[i][j].resize(25*n+1);
			fill(all(dp[i][j]),-infi);
		}
	}
	dp[1][0][0]=0;
	for(int i=0; i<n; i++){

		for(int j=0; j<=n; j++){
			for(int k=0; k<=25*n; k++) {
                dp[0][j][k]=dp[1][j][k];
                dp[1][j][k]=-infi;
			}
        }

		for(int j=0; j<=n; j++){
			for(int k=0; k<=25*n; k++) {
				if(j+1<=n&&k+a[i].se<=25*n) dp[1][j+1][k+a[i].se]=max(dp[1][j+1][k+a[i].se],dp[0][j][k]+a[i].fi);
				dp[1][j][k]=max(dp[1][j][k],dp[0][j][k]);
			}
        }
    }
	int ans=0;
	for(int i=0; i<=k0*25; i++) {
		ans=max(ans,min(i,dp[1][k0][i]));
	}
	cout<<ans<<endl;
}
int main(){
solve();

}