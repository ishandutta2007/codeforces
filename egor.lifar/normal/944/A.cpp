#include <bits/stdc++.h>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &x, T2 y){if (x > y) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 &x, T2 y){if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size();
#define left left228
#define right right228
#define y1 y1228
#define x1 x1228
#define pb push_back





int main() {
	//freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	a--, b--;
	int cnt = 0;
	int ss = 1;
	while (ss < n) {
		cnt++;
		ss <<= 1;
	}
	//cout << cnt << endl;
	for (int st = n; st >= 1; st /= 2) {
		if (a / st != b / st) {
			if (st == n / 2) {
				cout << "Final!" << endl;
				return 0;
			}
			cout << cnt + 1 << endl;
			break;
		}
		cnt--;
	}
	return 0;
}