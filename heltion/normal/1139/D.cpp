#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
constexpr LL mod = 1000000007;
int mu[maxn];
LL dm, m;
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
vector<int> d[maxn];
LL dp[maxn];
bool vis[maxn];
LL dd(LL m, LL u){
	LL res = 0;
	for(int v : d[u]) {
		res += m / v * mu[v];
		res %= mod;
	}
	return res;
}
LL f(int u){
	for(int v : d[u]) if(v != u){
		dp[u] += (dp[v] + 1) * (dd(m / v, u / v)) % mod * dm % mod;
		dp[u] %= mod;
	}
	//cout << u << " " << dp[u] << endl;
	LL pu = m / u * dm % mod;
	dp[u] = (dp[u] + pu) * power(1 + mod - pu, mod - 2) % mod;
	return dp[u];
}
int main(){
	cin >> m;
	dm = power(m, mod - 2);
	for(int i = 1; i <= m; i += 1)
		for(int j = 1; i * j <= m; j += 1) d[i * j].push_back(i);
	for(int i = 1; i <= m; i += 1){
		if(i == 1) mu[i] = 1;
		else{
			int v = d[i][1];
			if(i / v % v == 0) mu[i] = 0;
			else mu[i] = mod - mu[i / v];
		}
	}
	LL ans = 0;
	for(int i = 2; i <= m; i += 1) ans = (ans + f(i) * dm % mod) % mod;
	cout << (ans + 1) % mod;
}