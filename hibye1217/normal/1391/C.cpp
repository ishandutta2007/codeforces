#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl '\n'
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

const ll mod = 1e9 + 7;
ll fac[1000020];
ll dp[1000020];

int main(){
	fac[1] = 1;
	dp[3] = 2;
	for (int i = 2; i <= 1e6; i++) fac[i] = (fac[i-1] * i) % mod;
	for (int i = 3; i < 1e6; i++){
		dp[i+1] = (fac[i]*(i-1)) % mod;
		dp[i+1] = (dp[i+1] + 2*dp[i]) % mod;
	}
	int n;
	cin >> n;
	cout << dp[n];
}