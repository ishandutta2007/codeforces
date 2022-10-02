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
const int MAXN = 5001;

string s;
int cnt[MAXN][26][26];
int cnts[26];


int main() {
	//freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0; i < sz(s); i++) {
		for (int j = 0; j < sz(s); j++) {
			cnt[j][s[i] - 'a'][s[(i + j) % sz(s)] - 'a']++;
		}
		cnts[s[i] - 'a']++;
	}
	double sum = 0.0;
	for (int i = 0; i < 26; i++) {
		double ver = 0.0;
		for (int j = 0; j < sz(s); j++) {
			double vers = 1.0;
			for (int t = 0; t < 26; t++) {
				if (cnt[j][i][t] == 0) {
					continue;
				}
				if (cnt[j][i][t] > 1) {
					vers -= double(cnt[j][i][t]) / cnts[i];
					continue;
				}
			}
			chkmax(ver, vers);
		}
		sum += ver * double(cnts[i]) / sz(s);
	}
	cout.precision(10);
	cout << fixed << sum << endl;
	return 0;	
}