#include <bits/stdc++.h>

using namespace std;
template<class T1, class T2> inline void chkmin(T1 &x, T2 const &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, T2 const &y) {if (x < y) x = y;}
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define left left228
#define right right228
const int MAXN = 1028;


int n, k;
int a[MAXN];
bool good[MAXN];
int c[MAXN];
int who[MAXN];
bool f[MAXN];


int getd(double x) {
	return floor(x + 0.5 + 1e-9);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.in", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		good[i] = true;
	}
	int uk = 0;
	int cnt = 0;
	while (cnt < n) {
		for (int i = 0; i < k; i++) {
			if (good[i] && uk < n) {
				c[i] = a[uk];
				who[i] = uk;
				good[i] = false;
				uk++;
			}
		}
		int add = 0;
		vector<pair<int, int> > st;
		for (int i = 0; i < k; i++) {
			if (!good[i]) {
				st.pb({a[who[i]] - c[i] + 1, who[i]});
				if (getd(double(100 * cnt) / double(n)) == a[who[i]] - c[i] + 1) {
					f[who[i]] = true;
				}
				c[i]--;
				if (c[i] == 0) {
					add++;
					good[i] = true;
				}
			}
		}
		cnt += add;
		//cout << getd(double(100 * cnt) / double(n)) << endl;
		// for (auto x: st) {
		// 	if (getd(double(100 * cnt) / double(n))  == x.first) {
		// 		f[x.second] = true;
		// 	}
		// }
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += f[i];
	}
	cout << ans << endl;
	return 0;
}