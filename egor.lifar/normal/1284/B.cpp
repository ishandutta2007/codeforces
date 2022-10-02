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
const int MAXN = 200228;



int n;
int mn[MAXN], mx[MAXN];
bool good[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int l;
    	cin >> l;
    	mn[i] = 1e9;
    	mx[i] = -1e9;
    	for (int j = 0; j < l; j++) {
    		int a;
    		cin >> a;
    		if (mn[i] < a) {
    			good[i] = true;
    		}
    		chkmax(mx[i], a);
    		chkmin(mn[i], a);
    	}
    }
    ll ans = 0;
    int cnt = 0;
    vector<int> st;
    for (int i = 0; i < n; i++) {	
    	if (good[i]) {
    		cnt++;
    	} else {
    		st.pb(mx[i]);
    	}
    }
    sort(all(st));
    for (int i = 0; i < n; i++) {	
    	if (good[i]) {
    		ans += n;
    	} else {
    		ans += cnt;
    		int f = upper_bound(all(st), mn[i]) - st.begin();
    		int g = sz(st) - f;
    		ans += g;
    	}
    }
    cout << ans << '\n';
}