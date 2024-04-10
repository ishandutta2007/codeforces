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




int n, m;
int cnt[50000000];
int res[100000];
int cur;


int getcnt(int x) {
	return cnt[x];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
  	cin >> n >> m;
  	for (int i = 1; i <= n; i++) {
  		for (int j = i + 1; j <= n; j++) {
  			cnt[i + j]++;
  		}
  		res[i] = i;
  	}
  	int sum = 0;
  	for (int i = 1; i <= n; i++) {
  		sum += cnt[res[i]];
  	}
  	if (sum < m) {
  		cout << -1 << endl;
  		return 0;
  	}
  	memset(cnt, 0, sizeof(cnt));
  	sum = 0;
  	for (int i = 1; i <= n; i++) {
  		cur = i - 1;
  		int dp = -1e9;
  		int opt = -1;
  		for (int t = max(res[i - 1] + 1, 1); t <= res[i - 1] + n * 3; t++) {
  			int gg = getcnt(t);
  			if (sum + gg <= m) {
  				if (dp < gg) {
  					dp = gg;
  					opt = t;
  				}  			
  			}
  		}
  		res[i] = opt;
  		sum += getcnt(res[i]);
  		for (int t = 1; t < i; t++) {
  			cnt[res[t] + res[i]]++;
  		}
  	}	
  	for (int i = 1; i <= n; i++) {
  		cout << res[i] << ' ';
  	}
  	cout << '\n';
    return 0;    
}