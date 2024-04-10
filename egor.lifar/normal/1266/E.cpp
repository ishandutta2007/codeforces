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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 200228;


int n;
int a[MAXN];
int q;
set<pair<int, int> > w[MAXN];
int cnt[MAXN];
ll res = 0;



void del(int u, pair<int, int> p) {
	cnt[p.second]--;
	if (cnt[p.second] < a[p.second]) {
		res++;
	}
}

void add(int u, pair<int, int> p) {
	cnt[p.second]++;
	if (cnt[p.second] <= a[p.second]) {
		res--;
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	res += a[i];
    }
    cin >> q;
    for (int its = 0; its < q; its++) {
    	int s, t, u;
    	cin >> s >> t >> u;
    	auto it = w[s].lower_bound(mp(t, 0));
    	if (it != w[s].end() && it->first == t) {
    		auto x = *it;
    		del(s, x);
    		w[s].erase(x);
    	}
    	if (u != 0) {
    		w[s].insert(mp(t, u));
    		add(s, mp(t, u));
    	}
    	cout << res << '\n';
    }
}