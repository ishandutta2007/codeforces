#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e4 + 10, H = 35;
int n, h;
double f[N][H][2], p[N][H][2], g[H][2], t[H][2], w1[H], w2[H];
int main() {
//	freopen("in.txt", "r", stdin);
	string str;
	cin >> str;
	cin >> n >> h;
	cout << fixed << setprecision(10);
	if(str == "Bob") {
		cout << n << '\n';
		return 0;
	}
	w1[0] = 0.5;
	for(int i = 1; i <= h; i ++) w1[i] = w1[i - 1] * 0.5;
	for(int i = 0; i <= h; i ++) {
		w2[i] = 1;
		for(int j = 0; j < i; j ++) w2[i] -= w1[j];
	}
	w1[h] = w2[h];
	// for(int i = 0; i <= h; i ++) cout << w1[i] << ' '; cout << '\n';
	// for(int i = 0; i <= h; i ++) cout << w2[i] << ' '; cout << '\n';
	t[0][0] = 1;
	for(int i = 1; i < n; i ++) {
		for(int j = 0; j <= h; j ++) {
			f[i][j][0] = g[j][0];
			f[i][j][1] = g[j][1];
			p[i][j][0] = t[j][0];
			p[i][j][1] = t[j][1];
		}
		for(int j = 0; j <= h; j ++) g[j][0] *= 1 - w2[j], g[j][1] *= 1 - w2[j], t[j][0] *= 1 - w2[j], t[j][1] *= 1 - w2[j];
		for(int j = 0; j <= h; j ++) {
			for(int k = j; k <= h; k ++) {
				g[k][0] += (f[i][j][0] + p[i][j][0] * (1 << k)) * w1[k];
				t[k][0] += p[i][j][0] * w1[k];
			}
			for(int k = 0; k < h; k ++) {
				g[k][1] += (f[i][j][0] + p[i][j][0] * (1 << k)) * w1[k] * w2[max(j, k + 1)];
				t[k][1] += p[i][j][0] * w1[k] * w2[max(j, k + 1)];
			}
		}
		for(int j = 0; j <= h; j ++) {
			for(int k = 0; k <= j; k ++) {
				g[k][1] += (f[i][j][1] + p[i][j][1] * (1 << k)) * w1[k];
				t[k][1] += p[i][j][1] * w1[k];
			}
		}
	}
	double ans = 0;
	for(int i = 0; i <= h; i ++) ans += g[i][0] * w2[i] + g[i][1];
	cout << ans + 1 << '\n';
	return 0;
}