#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
const ll mod = 1000000007;

ll p,za;
string str;
vector<ll>num,val;
int dp[3405][3405][2][2];
typedef vector<int> vi;

//a/p, a%p
pair<vi,int>wr(vi a){
	reverse(a.begin(),a.end());
	vi b; b = a;
	for(auto &at:b) at = 0;
	ll cur = 0;
	rep(i,a.size()){
		int v = a[i];
		cur = cur*10LL+v;
		assert(cur/p <= 20);
		
		b[i] += cur/p;
		cur %= p;
	}
	int ret2 = (int)(cur);
	for(int i=b.size()-1;i>=1;i--){
		if(b[i] >= 10){
			b[i-1] += b[i] / 10;
			b[i] %= 10;
		}
	}
	assert(b[0] < 10);
	reverse(b.begin(),b.end());
	while(b.size() && b.back() == 0) b.pop_back();
	return mp(b,cur);
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	cin >> p >> za ;
	cin>>str;//rep(i,1000) str.pb('9');//>> str;
	if(str == "0"){
		puts("0");
		return 0;
	}
	reverse(str.begin(),str.end());
	vi vacl;
	ll all = 0, bs = 1;
	rep(i,str.size()){
		vacl.pb(str[i]-'0');
	}
	while(1){
		auto at = wr(vacl);
		num.pb(at.sc);
		vacl = at.fi;
		if(vacl.empty()) break;
	}
	//cout << num.size() << endl;
	//rep(i,num.size()) cout << num[i] << endl;
	val = num;
	dp[0][0][0][0] = 1;
	ll pw = p;
	ll rev2 = modpow(2,mod-2);
	ll ans = 0;
	rep(i,val.size()){
		rep(j,i+1){
			rep(a,2){
				rep(b,2){
					if(dp[i][j][a][b] == 0) continue;
					ll N[3]={val[i], 1, (pw-1-val[i]+mod)%mod};
					for(int x=0;x<3;x++){
						int nwa = a;
						if(x == 0) nwa = 0;
						else if(x == 2) nwa = 1;
						int nwb;
						//small
						nwb = 0;
						ll w0 = N[x] * (N[x]-1) % mod * rev2 % mod ;
						rep(y,x) w0 += N[x] * N[y] % mod;
						ll dp0 = 1LL*dp[i][j][a][b]*w0%mod;
						dp[i+1][j+nwb][nwa][nwb] += dp0;
						if(dp[i+1][j+nwb][nwa][nwb] >= mod) dp[i+1][j+nwb][nwa][nwb] -= mod;
						if(j+nwb >= za){
							if(i+1 < val.size()){
								if(nwb == 0) ans += dp0;
							}
							else {
								if(nwb == 0 && nwa == 0) ans += dp0;
							}
						}
						//same
						nwb = b;
						ll w1 = N[x];
						ll dp1 = 1LL*dp[i][j][a][b]*w1%mod;
						dp[i+1][j+nwb][nwa][nwb] += dp1;
						if(dp[i+1][j+nwb][nwa][nwb] >= mod) dp[i+1][j+nwb][nwa][nwb] -= mod;
						bool bad = 0;
						if(val[i] == 0 && x == 1) bad = 1;
						else if(val[i] > 0 && x == 0) bad = 1;
						
						if(j+nwb >= za){
							if(i+1 < val.size()){
								if(nwb == 0) ans += dp1-(bad?dp[i][j][a][b]:0);
							}
							else {
								if(nwb == 0 && nwa == 0) ans += dp1-(bad?dp[i][j][a][b]:0);
							}
						}
						//big
						nwb = 1;
						ll w2 = N[x] * pw  - (w0+w1) ;
						w2 = (w2%mod+mod)%mod;
						ll dp2 = 1LL*dp[i][j][a][b]*w2%mod;
						dp[i+1][j+nwb][nwa][nwb] += dp2;
						if(dp[i+1][j+nwb][nwa][nwb] >= mod) dp[i+1][j+nwb][nwa][nwb] -= mod;
						//cout << ans << " " << dp[i][j][a][b]<< " "<<i << j << a << b << endl;
					}
				}
			}
		}
	}
	cout <<(ans%mod+mod)%mod<<endl;
}