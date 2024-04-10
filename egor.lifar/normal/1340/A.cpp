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
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 100228;


int n;
int p[MAXN];
int where[MAXN];
int score[MAXN];


void solve() {
	cin >> n;
	set<int> frees;
	multiset<int> val;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		where[p[i]] = i;
		frees.insert(i);
		score[i] = 1;
		val.insert(score[i]);
	}
	bool bad = false;
	for (int i = 1; i <= n; i++) {
		int g = *val.rbegin();
		int j = where[i];
		int g1 = score[j];
		if (g != g1) {
			bad = true;
			break;
		}
		val.erase(val.find(g));
		frees.erase(j);
		auto k = frees.lower_bound(j);
		if (k != frees.end()) {
			int t = *k;
			val.erase(val.find(score[t]));
			score[t] += score[j];
			val.insert(score[t]);
		}
	}
	if (!bad) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   // read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}