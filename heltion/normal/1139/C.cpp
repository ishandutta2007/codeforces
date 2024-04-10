#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
constexpr LL mod = 1000000007;
int f[maxn];
int getf(int u){
	return f[u] < 0 ? u : f[u] = getf(f[u]);
}
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1) f[i] = -1;
	for(int i = 1; i < n; i += 1){
		int u, v, x;
		cin >> u >> v >> x;
		if(x == 0){
			u = getf(u);
			v = getf(v);
			if(f[u] < f[v]) f[u] += f[v], f[v] = u;
			else f[v] += f[u], f[u] = v;
		}
	}
	LL ans = power(n, k);
	for(int i = 1; i <= n; i += 1) if(f[i] < 0) ans = (ans - power(-f[i], k) + mod) % mod;
	cout << ans;
}