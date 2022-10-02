#include <bits/stdc++.h>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &x, T2 y){if (x > y) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 &x, T2 y){if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define x1 x1228
#define pb push_back
const int MAXN = 200001;

int n;
int x[MAXN];
map<int, int> cnt;


int main() {
//	freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		sum += x[i];
		cnt[x[i]]++;
	}
	vector<int> f;
	for (auto x: cnt) {
		f.push_back(x.first);
	}
	if (sz(f) == 1) {
		cout << n << endl;
		for (int i = 0; i < n; i++) {
			cout << f[0] << ' ';
 		}
 		cout << '\n';
 		return 0;
	}
	if (sz(f) == 2) {
		if (f.back() != f[0] + 1) {
			f.push_back(f[0] + 1);
			swap(f[1], f[2]);
		}
	}
	if (sz(f) == 2) {
		cout << n << endl;
		for (int i = 0; i < n; i++) {
			cout << x[i] << ' ';
 		}
 		cout << '\n';
 		return 0;
	}
	int ans = n + 1;
	for (int i = 0; i <= n; i++) {
		long long rest = sum - 1LL * i * f[0];
		int m = n - i;
		//a + b == m
		//a * f[0] + a + b * f[0] + 2 * b == sum
		rest -= 1LL * m * (f[0] + 1);
		int bt = rest;
		if (bt >= 0 && bt <= m) {
			int cnts = min(cnt[f[0]], i) + min(cnt[f[0] + 1], m - bt) + min(cnt[f[0] + 2], bt);
			if (cnts < ans) {
				ans = cnts;
			}
		}
	} 
	for (int i = 0; i <= n; i++) {
		long long rest = sum - 1LL * i * f[0];
		int m = n - i;
		//a + b == m
		//a * f[0] + a + b * f[0] + 2 * b == sum
		rest -= 1LL * m * (f[0] + 1);
		int bt = rest;
		if (bt >= 0 && bt <= m) {
			int cnts = min(cnt[f[0]], i) + min(cnt[f[0] + 1], m - bt) + min(cnt[f[0] + 2], bt);
			if (ans == cnts) {
				cout << ans << '\n';
				for (int j = 0; j < i; j++) {
					cout << f[0] << ' ';
				}
				for (int j = 0; j < m - bt; j++) {
					cout << f[0] + 1 << ' ';
				}
				for (int j = 0; j < bt; j++) {
					cout << f[0] + 2 << ' ';
				}
				cout << '\n';
				return 0;
			}
		}
	}
	return 0;
}