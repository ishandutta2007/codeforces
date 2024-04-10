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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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
using ld = long double; 
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}


const int MAXN = 10005;

int n;
bool good[MAXN];
int p[MAXN];
int p1[MAXN];
int q[MAXN];
int q1[MAXN];
 int cnt = 0;


int query(int a) {
	cnt++;
	assert(cnt <=2 * n);
	cout << "? " << a << endl;
	int res = q[a]; 
	cin >> res;
	// for (int i = 1; i <= n; i++) {
	// 	q1[i] = q[p1[i]];
	// }
	// for (int i = 1; i <= n; i++) {
	// 	q[i] = q1[i];
	// }
	return res;
}
mt19937 as;

int was[MAXN];
int uk;


void solve() {
	cin >> n;
//	n = 10;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		p1[i] = i;
		good[i] = false;
		q[i] = i;
	}
	//shuffle(p1 + 1, p1 + n + 1, as);
	int cnte = 0;
	for (int i = 1; i <= n; i++) {
		if (good[i]) {
			continue;
		}
		uk++;
		int last = -1;
		while (true) {
			int t = query(i);
			good[t] = true;
			if (last != -1) {
				p[last] = t;
			}
			last = t;
			if (was[last] == uk) {
				break;
			}
			was[last] = uk;
		}
	}
	cout << "!";
	for (int i = 1; i <= n; i++) {
		//assert(p[i] == p1[i]);
		cout << ' ' << p[i];
	}
	cout << endl;
}


int main(){
	//cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 10000;
	cin >> t;
	while (t--) {
		solve();
	}
}