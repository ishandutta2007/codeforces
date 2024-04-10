	#include <bits/stdc++.h>
	using namespace std;
	constexpr int maxn = 200, mod = 998244353;
	inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
	inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
	inline int mul(int a, int b) {return 1ll * a * b % mod;}
	inline void upd(int &a, int b) {a = add(a, b);}
	inline void dpu(int &a, int b) {a = sub(a, b);}
	int n, m, k;
	struct Matrix {
		int a[maxn + 5][maxn + 5];
		int* operator [] (int x) {return a[x];}
		Matrix (int I = 0) {
			memset(a, 0, sizeof(a));
			for(int i = 0; i < n + n; i ++) a[i][i] = I;
		}
		friend Matrix operator * (Matrix x, Matrix y) {
			Matrix z;
			for(int i = 0; i < n + n; i ++) {
				for(int j = 0; j < n + n; j ++) {
					for(int k = 0; k < n + n; k ++) {
						upd(z[i][j], mul(x[i][k], y[k][j]));
					}
				}
			}
			return z;
		}
		void debug() {
			cout << "--------------\n";
			for(int i = 0; i < n + n; i ++) {
				for(int j = 0; j < n + n; j ++) {
					cout << a[i][j] << " \n"[j == n + n - 1];
				}
			}
		}
	};
	inline Matrix fastpow(Matrix a, int b) {
		Matrix ans = Matrix(1);
		for(; b; b >>= 1, a = a * a) if(b & 1) ans = ans * a;
		return ans;
	}
	int main() {
		ios::sync_with_stdio(false);
		cin.tie(0), cout.tie(0);
		cin >> n >> m >> k;
		if(k == 1) {
			cout << 0 << '\n';
			return 0;
		}
		Matrix bs, start;
		for(int i = 0; i < m; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			bs[u + n][v + n] ++;
			bs[v + n][u + n] ++;
			dpu(bs[u][u + n], 1);
			dpu(bs[v][v + n], 1);
			start[u][v + n] ++;
			start[v][u + n] ++;
		}
		for(int i = 0; i < n; i ++) {
			upd(bs[i][i + n], 1);
			bs[i + n][i] ++;
			start[i][i] = 1;
		}
		// bs.debug(), start.debug();
		start = start * bs;
		// start.debug();
		for(int i = 0; i < n; i ++) dpu(start[i][i + n], 1);
		// start.debug();
		Matrix end = start * fastpow(bs, k - 2);
		// end.debug();
		int ans = 0;
		for(int i = 0; i < n; i ++) upd(ans, end[i][i + n]);
		cout << ans << '\n';
		return 0;
	}