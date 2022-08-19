#include<bits/stdc++.h>//a
using namespace std; //h
typedef long long ll;
ll n, m, k, c[30][30], a[30], dp[30][1 << 19]; //h
void solve() { // a
cin >> n >> m >> k; //h
for(int i = 0; i < n; i++) cin >> a[i]; // a
for (int i =0; i < k; ++i) { //h
int x, y; // a
cin >> x >> y; //h
x--, y--; // a
cin >> c[x][y]; //h
} // a
ll res = 0; //h
for(int msk = 1; msk < (1 << n); msk++) { // a
for (int u = 0; u < n; ++u) { //h
for(int v = 0; (msk & (1 << u)) && v < n; v++) dp[u][msk] = max(dp[u][msk], dp[v][msk ^ (1 << u)] + ((msk == (1 << u) || !(msk & (1 << v))) ? 0 : c[v][u]) + a[u]);
if (__builtin_popcount(msk) == m) res = max(res, dp[u][msk]); //h
} // a
} //h
cout << res << '\n'; // a
} //h
int main() { // a
solve(); //h
return 0; // a
}