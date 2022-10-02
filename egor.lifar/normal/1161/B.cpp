 /*
 



















 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
const string FILENAME = "input";
const int MAXN = 200228;


int n, m;
int a[MAXN], b[MAXN];
vector<int> kek[MAXN];
int used[MAXN];
int keks[MAXN];
int uk = 0;


int getlen(int a, int b) {
	if (a <= b) {
		return b - a;
	}
	return n - a + b;
}



bitset<200001> kekt, kek1;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
		if (b[i] - a[i] > n - b[i] + a[i]) {
			swap(a[i], b[i]);
		}
		//cout << a[i] << ' ' << b[i] << endl;
		kek[getlen(a[i], b[i])].pb(i);
	}
	int wow = 0;
	for (int i = 1; i <= n; i++) {
		if (kek[i].empty()) {
			continue;
		}
		wow++;
		vector<int> g;
		for (auto x: kek[i]) {
			g.pb(a[x]);
			g.pb(b[x]);
		}
		sort(all(g));
		int st = g[0];
		for (auto &x: g) {
			x -= st;
		}
		vector<int> pr;
		int ff = 0;
		for (auto x: g) {
			pr.pb(x);
			used[x]++;
			if (x != 0) {
				ff = __gcd(ff, x);
			}
		}
		int border = getlen(g.back(), g[0]);
		vector<pair<int, int> > kek;
		for (auto x: g) {
			if (kek.empty() || kek.back().first != x) {
				kek.pb({x, 1});
			} else {
				kek.back().second++;
			}
		}
		for (auto x: g) {
			kekt[x] = true;
			kek1[x] = true;
			kek1[x + n] = true;
		}
		pr.resize(distance(pr.begin(), unique(all(pr))));
		for (auto step: pr) {
			if (step == 0) {
				continue;
			}
			if (keks[step] != wow - 1) {
				continue;
			} 
			if ((1LL * step * sz(g)) % n != 0 || step < border) {
				continue;
			}
			int kesk = n / __gcd(step, n);
		//	cout << kek << endl;
			int tp = __gcd(step, n);
			//cout << ff << ' ' << tp << endl;
			if (tp % ff != 0) {
				continue;
			}
			if (kesk > sz(kek)) {
				continue;
			}
			if ((kek1 & (kekt << step)).count() != sz(pr)) {
				continue;
			}
			 bool bad = false;
			// vector<pair<int, int> > sts;
			// for (auto x: kek) {
			// 	if (!used[x.first]) {
			// 		continue;
			// 	}
			// 	int cur = x.first;
			// 	while (true) {
			// 		int f = (cur + step) % n;
			// 		if (used[f] != x.second) {
			// 			bad = true;
			// 			break;
			// 		}
			// 		used[f]-= x.second;
			// 		sts.pb({f, x.second});
			// 		cur = f;
			// 		if (cur == x.first) {
			// 			break;
			// 		}
			// 	}
			// 	if (bad) {
			// 		break;
			// 	}
			// }
			// for (auto x: sts) {
			// 	used[x.first]+=x.second;
			// }
			if (!bad) {
				keks[step]++;
			}
		}
		for (auto x: g) {
			kekt[x] = false;
			kek1[x] = false;
			kek1[x + n] = false;
		}
		for (auto x: g) {
			used[x]--;
		}
	}
	for (int i =1; i < n; i++) {
		if (keks[i] == wow) {
			cout << "Yes\n";
			exit(0);
		}
	}
	cout << "No\n";
	return 0; 	
}