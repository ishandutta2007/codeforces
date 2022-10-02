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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 150228;


int n, q;
vector<pair<int, char> > g[MAXN];
int deep[MAXN];
int curmax[MAXN];
int cnt[MAXN][27];
vector<int> v[MAXN];
int pr[MAXN];
int len[MAXN];
int pc[MAXN];
bool bad[MAXN];
bool good[MAXN];
int maxcnt[MAXN][27];
int cntbad;
bool badv[MAXN];
int lenl[MAXN];
int sum[MAXN];
int who[MAXN];


void recalc1(int u) {
	for (auto h: g[u]) {
		for (int c = 0; c < 26; c++)  {
			chkmax(maxcnt[u][c], maxcnt[h.first][c] + (pc[h.first] == c));
		}
	}
	sum[u] = 0;
	for (int c = 0; c < 26; c++) {
		sum[u] += maxcnt[u][c];
	}
}


void recalc(int u) {
	for (int c = 0; c < 26; c++) {
		maxcnt[u][c] = 0;
	}
	for (auto h: v[u]) {
		for (int c = 0; c < 26; c++) {
			chkmax(maxcnt[u][c], maxcnt[h][c] + cnt[h][c]);
		}
	}
	sum[u] = 0;
 	for (int c = 0; c < 26; c++) {
		sum[u] += maxcnt[u][c];
	}
}



void update(int u) {
	if (badv[u]) {
		cntbad--;
	}
	badv[u] = false;
 	int score = 0;
	for (int c = 0; c < 26; c++) {
		score += maxcnt[u][c];
	}
	if (score > lenl[u]) {
		badv[u] = true;
		cntbad++;
	}
}


void dfs(int u) {
	for (auto h: g[u]) {
		deep[h.first] = deep[u] + 1;
		dfs(h.first);
		lenl[u] = lenl[h.first] + 1;
	}
	recalc1(u);
	update(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int p;
		char c;
		cin >> p >> c;
		p--;
		if (c == '?')  {
			c = 'z' + 1;
		
		}
		g[p].pb({i, c});
		pr[i] = p;

		pc[i] = c - 'a';
	}
	dfs(0);
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (g[i].empty()) {
			s.insert(deep[i]);
		}
	}
	if (sz(s) != 1) {
		for (int i = 0; i < q; i++) {
			cout << "Fou\n";
		}
		return 0;
	}
	//Shi Yes
	//Fou No
	for (int i = 1; i < n; i++) {
		if (pr[i] && sz(g[pr[i]]) == 1 && sz(g[i]) != 1) {
			int cur = pr[i];
			cnt[i][pc[i]]++;
			len[i] = 1;
 			while (cur && sz(g[cur]) == 1) {
				cnt[i][pc[cur]]++;
				len[i]++;
				bad[cur] = true;
				who[cur] = i;
 				cur = pr[cur];
			}
			pr[i] = cur;
			who[i] = i;
 			bad[i] = true;
			good[i] = true;
		}
	}
	good[0] = true;
	for (int i = 1; i < n; i++) {
		if (!bad[i]) {
			cnt[i][pc[i]]++;
			len[i] = 1;
			good[i] = true;
			who[i] = i;
		}
	}
	for (int i = 1; i < n; i++) {
		if (good[i]) {
			v[pr[i]].pb(i);
		}
	}
	for (int it = 0; it < q; it++) {
		int id;
		char c;
		cin >> id >> c;
		id--;
		if (c == '?') {
			c = 'z' + 1;
		}
 		int cc = c - 'a';
		cnt[who[id]][pc[id]]--;
		pc[id] = cc;
		cnt[who[id]][pc[id]]++;
		id = who[id];
		int g = pr[id];
		while (true) {
			recalc(g);
			update(g);
			if (g == 0) {
				break;
			}
			g = pr[g];
		}
	//	cout << cntbad << endl;
		if (cntbad) {
			cout << "Fou\n";
			continue;
		}
		cout << "Shi ";
		int res = 0;
		for (int i = 0; i < 26; i++) {
			res += (maxcnt[0][i] + lenl[0] - sum[0]) * (i + 1);
 		}
 		cout << res << '\n';
	}
}