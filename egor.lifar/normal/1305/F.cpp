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
ll a[MAXN];
mt19937 as;
bool ok[MAXN * 10];
bool was[MAXN * 10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    double f = clock();
  	cin >> n;
  	for (int i = 0; i < n; i++) {
  		cin >> a[i];
  	}
  	vector<ll> vs;
  	for (int i = 2; i <= 1000000; i++) {
  		if (!ok[i]) {
  			vs.pb(i);
  			if (1000000 / i < i) {
  				continue;
  			}
  			for (int j = i * i; j <= 1000000; j += i) {
  				ok[j] = true;
  			}
  		}
  	}
  	int cnt = 0;
  	for (int i = 0; i < n; i++) {
  		if (a[i] % 2 == 1) {
  			cnt++;
  		}
  	}
  	int ans = cnt;
  	vector<ll> kek;
  	for (int i = 0; i < n; i++) {
  		if (a[i] > 1) {
  			kek.pb(a[i] - 1);
  		}
  		kek.pb(a[i]);
  		kek.pb(a[i] + 1);
  	}
  	sort(all(kek));
  	kek.resize(distance(kek.begin(), unique(all(kek))));
  	as.seed(time(NULL));
  	shuffle(a, a + n, as);
  	while ((clock() - f) / CLOCKS_PER_SEC < 2.0) {
  		int id = as() % sz(kek);
  		ll val = kek[id];
  		int it = 0;
  		vector<ll> pd;
  		while (it < sz(vs) && vs[it] <= val / vs[it]) {
  			if (val % vs[it] == 0) {
  				pd.pb(vs[it]);
  				while (val % vs[it] == 0) {
  					val /= vs[it];
  				}
  			}
  			it++;
  		}
  		if (val != 1) {
  			pd.pb(val);
  		}
  		shuffle(all(pd), as);
  		for (auto x: pd) {
  			if (x < 1000000 && was[x]) {
  				continue;
  			}
  			if (x < 1000000) {
  				was[x] = true;
  			}
  			ll sum = 0;
  			for (int i = 0; i < n; i++) {
  				ll d = a[i] % x;
  				if (a[i] < x) {
  					sum += x - a[i];
  				} else {
  					sum += min(d, x - d);
  				}
  				if (sum >= ans) {
  					break;
  				}
  			}
  			chkmin(ans, sum);
  		}
  	}
  	cout << ans << '\n';
    return 0;    
}