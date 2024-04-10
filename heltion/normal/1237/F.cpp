//Author: Heltion
//Date: 10-16-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 3600 + 10;
constexpr int mod = 998244353;
void add(int &x, int y){
	x += y;
	if(x >= mod) x -= mod;
}
int h, w, n, rh, rw;
int vr[maxn], vc[maxn];
int dpr[maxn][maxn], dpc[maxn][maxn];
int c[maxn][maxn];
int f[maxn];
void DP(int n, int v[], int dp[][maxn]){
	dp[0][0] = 1;
	for(int i = 1; i <= n; i += 1){
		for(int j = 0; j <= n; j += 1) dp[i][j] = dp[i - 1][j];
		if(i >= 2 and not v[i - 1] and not v[i]){
			for(int j = 0; j <= n; j += 1) add(dp[i][j + 1], dp[i - 2][j]);
		}
	}
}
int main(){
	for(int i = 0; i < maxn; i += 1)
		for(int j = 0; j <= i; j += 1){
			if(i == j or j == 0) c[i][j] = 1;
			else{
				c[i][j] = c[i - 1][j - 1];
				add(c[i][j], c[i - 1][j]);
			}
		}
	for(int i = 0; i < maxn; i += 1){
		if(i == 0) f[i] = 1;
		else f[i] = 1LL * f[i - 1] * i % mod;
	}
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	cin >> h >> w >> n;
	for(int i = 1; i <= 2 * n; i += 1){
		int r, c;
		cin >> r >> c;
		vr[r] = true;
		vc[c] = true;
	}
	DP(h, vr, dpr);
	DP(w, vc, dpc);
	for(int i = 1; i <= h; i += 1) if(not vr[i]) rh += 1;
	for(int i = 1; i <= w; i += 1) if(not vc[i]) rw += 1;
	int ans = 0;
	for(int a = 0; a <= rh; a += 1)
		for(int b = 0; b <= rh; b += 1)
			if(a + b * 2 <= rh and a * 2 + b <= rw){
				add(ans, 1LL * dpr[h][b] * c[rh - 2 * b][a] % mod
					* dpc[w][a] % mod * c[rw - 2 * a][b] % mod
					* f[a] % mod * f[b] % mod);
			}
	cout << ans;
	return 0;
}