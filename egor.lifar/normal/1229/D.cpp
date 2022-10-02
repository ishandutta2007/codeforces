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
using ll = long long;
const string FILENAME = "input";
const int MAXN = 200228;


bool groups[130];



vector<int> composite(vector<int> a, vector<int> b) {
	vector<int> c;
	c.resize(sz(a));
	for (int i = 0; i < sz(a); i++) {
		c[b[i]] = a[i];
	}
	return c;
}


map<vector<int>, int> who;
vector<int> g[130];
int res[130][130];


int composite(int a, int b) {
	return who[composite(g[a], g[b])];
}

vector<int> basis;
int n, k;
vector<int> a[MAXN];
int cnts;
vector<int> kk;


void init() {
	memset(groups, 0, sizeof(groups));
	basis.clear();
	cnts = 1;
	groups[0] = true;
	kk.clear();
	kk.push_back(0);
}



void add(int st) {
	bool need = false;
	for (auto x: kk) {
		auto y = res[x][st];
		if (!groups[y]) {
			need = true;
			break;
		}
	}
	if (need) {
		basis.pb(st);
		queue<int> kek;
		for (auto z: kk) {
			kek.push(z);
		}
		while (!kek.empty()) {
			auto a = kek.front();
			kek.pop();
			for (auto k: basis) {
				auto y = res[a][k];
				if (!groups[y]) {
					groups[y] = true;
					cnts++;
					kk.pb(y);
					kek.push(y);
				}
			}
		}
	}
}


int as[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		a[i].resize(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	vector<int> t;
	t.resize(k);
	for (int j = 0; j < k; j++) {
		t[j] = j;
	}
	int uk = 0;
	do {
		who[t] = uk;
		g[uk] = t;
		uk++;
	} while (next_permutation(all(t)));
	for (int i = 0; i < n; i++) {
		as[i] = who[a[i]]; 
	}
	for (int i = 0; i < uk; i++) {
		for (int j = 0; j < uk; j++) {
			res[i][j] = composite(i, j);
		}
	}
	ll res = 0;
	vector<pair<int, int > > kek;
	for (int i = 0; i < n; i++) {
		init();
		vector<pair<int, int > > keky;
		pair<int, int> fx = mp(i, as[i]);
		keky.pb(fx);
		for (auto x: kek) {
			if (x.second == as[i]) {
				continue;
			}
			keky.pb(x);
		}
		kek = keky;
		int last = i;
		for (auto z: kek) {
			res += (last - z.first) * cnts;
			add(z.second);
			last = z.first;
		}
		res += (last + 1) * cnts;
	}
	cout << res << endl;
	return 0;
}