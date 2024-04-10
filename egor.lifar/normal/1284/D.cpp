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
#define rank rank228
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
const int MAXN = 400229;



int n;
int sa[MAXN], ea[MAXN], sb[MAXN], eb[MAXN];
map<int, vector<pair<int, int> > > event;
int f[MAXN];
vector<int> tb;


void inc(int i, int val) {
	for (int j = i; j < sz(tb); j |= (j + 1)) {
		f[j] += val;
	}
}

int get(int i) {
	int res = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) {
		res += f[i];
	}
	return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    for (int it = 0; it < 2; it++) {
	    tb.clear();
	 	event.clear();
	     for (int i = 0; i < n; i++) {	
	    	event[sa[i]].pb({i, 1});
	    	event[ea[i]].pb({i, -1});
	    	tb.pb(sb[i]);
	    	tb.pb(eb[i]);
	    }
	    sort(all(tb));
	    tb.resize(distance(tb.begin(), unique(all(tb))));
	    for (int i = 0; i < n; i++) {
	    	sb[i] = lower_bound(all(tb), sb[i]) - tb.begin();
	    	eb[i] = lower_bound(all(tb), eb[i]) - tb.begin();
	    }
	    memset(f, 0, sizeof(f));
	    for (auto x: event) {
	    	for (auto y: x.second) {
	    		if (y.second == 1) {
	    			if (get(eb[y.first]) - get(sb[y.first] - 1)) {
	    				cout << "No\n";
	    				exit(0);
	    			}
	    		}
	    	}
	    	for (auto y: x.second) {
	    		if (y.second == -1) {
	    			inc(sb[y.first], 1);
	    			inc(eb[y.first], 1);
	    		}
	    	}
	    }
	    memset(f, 0, sizeof(f));
	    event.clear();
	    for (int i = 0; i < n; i++) {
	    	sa[i] *= -1;
	    	ea[i] *= -1;
	    	swap(sa[i], ea[i]);
	    	event[sa[i]].pb({i, 1});
	    	event[ea[i]].pb({i, -1});
	    }
	    for (auto x: event) {
	    	for (auto y: x.second) {
	    		if (y.second == 1) {
	    			if (get(eb[y.first]) - get(sb[y.first] - 1)) {
	    				cout << "No\n";
	    				exit(0);
	    			}
	    		}
	    	}
	    	for (auto y: x.second) {
	    		if (y.second == -1) {
	    			inc(sb[y.first], 1);
	    			inc(eb[y.first], 1);
	    		}
	    	}
	    }
	    for (int i = 0; i < n; i++) {
	    	swap(sa[i], sb[i]);
	    	swap(eb[i], ea[i]);
	    }
	}
    cout << "Yes\n";
}