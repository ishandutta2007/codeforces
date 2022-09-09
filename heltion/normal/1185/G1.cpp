//Author: Heltion
//Date: 2019-06-19
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
constexpr int maxn = 15;
int t[maxn], g[maxn];
LL F[1 << maxn][4];
void add(LL &x, LL y){
	x += y;
	if(x >= mod) x -= mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, T;
	cin >> n >> T;
	for(int i = 0; i < n; i += 1) cin >> t[i] >> g[i];
	for(int i = 0; i < n; i += 1)
		F[1 << i][g[i]] = 1;
	for(int i = 1; i < (1 << n); i += 1)
		for(int j = 1; j <= 3; j += 1)
			for(int k = 0; k < n; k += 1) if(g[k] != j and ((1 << k) & i) == 0){
				add(F[(1 << k) | i][g[k]], F[i][j]);
			}
	LL ans = 0;
	for(int i = 1; i < (1 << n); i += 1){
		int tt = 0;
		for(int j = 0; j < n; j += 1) if((1 << j) & i) tt += t[j];
		if(tt == T){
			add(ans, F[i][1]);
			add(ans, F[i][2]);
			add(ans, F[i][3]);
		}
	}
	cout << ans;
	return 0;
}