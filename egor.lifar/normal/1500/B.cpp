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
const string FILENAME = "input";
const int MAXN = 500228;



int n, m;
ll k;
int a[MAXN];
int where[MAXN * 2];
int b[MAXN];



int gcd(int a, int b) {
	while (a) {
		b %= a;
		swap(a, b);
	} 
	return b;
}


int when[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
 	cin >> n >> m >> k;
 	for (int i = 0; i < n; i++) {
 		cin >> a[i];
 	}
 	for (int i = 1; i <= 1000000; i++) {
 		where[i] = -1;
 	}
 	for (int i = 0; i < m; i++) {
 		cin >> b[i];
 		when[i] = -1;
 		where[b[i]] = i;
 	}
 	ll cur = 0;
 	for (int f = 0; f <= m; f++) {
 		if (when[cur] == -1) {
 			when[cur] = f;
 		}
 		cur += n;
 		cur %= m;
 	}
 	int f = gcd(n, m);
 	ll d = (ll)n * m / f;
 	ll l = 1;
 	ll r = 1e18;
 	while (l < r) {
 		ll mid = (l + r) >> 1;
 		ll have = k;
 		for (int i = 0; i < n; i++) {
 			if (where[a[i]] == -1) {
 				have -= mid / n + (mid % n > i);
 			} else {
 				int pos = where[a[i]];
 				have -= mid / n + (mid % n > i);
 				int need = ((pos - i) % m + m) % m;
 				if (when[need] != -1) {
 					ll f = (ll)n * when[need] + i;
 					if (f + 1 <= mid) {
 						ll can = mid - f - 1;
 						have++;
 						have += can / d;
 					}
 				}
 			}
 			if (have <= 0) {
 				break;
 			}
 		}
 		if (have <= 0) {
 			r = mid; 
 		} else {
 			l = mid + 1;
 		}
 	}
 	cout << l << '\n';
}