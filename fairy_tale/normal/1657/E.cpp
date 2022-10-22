#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif
 
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
 
const int maxn = 1e6 + 5;
const int mod = 998244353;

int c[255][255];
int p[255][62505]; // p[i][j] = i ^ j
LL f[255][255];
 
int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, k;
	cin >> n >> k;
	n--;
	
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	for (int i = 1; i <= k; i++) {
		p[i][0] = 1;
		for (int j = 1; j <= n * n; j++) p[i][j] = 1LL * p[i][j - 1] * i % mod;
	}
	
	f[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int x = 0; x <= j; x++) f[i][j] += 1LL * c[j][x] * p[k - i + 1][x * (j - x) + c[x][2]] % mod * f[i - 1][j - x] % mod;
			f[i][j] %= mod;
		}
	}
	
	cout << f[k][n] << endl;
 
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}