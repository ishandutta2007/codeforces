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
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 200228;
const ll Mod = 998244353;


ll sum(ll a, ll b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}
 
 
ll mul(ll a, ll b) {
	return ((ll)a * b) % Mod;
}


ll powm(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}

int n, k;
int a[MAXN], b[MAXN];
int where[MAXN];


void solve() {
	cin >> n >> k;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		where[a[i]] = i;
		s.insert(i);
	}	
	set<int> kek;
	for (int i = 0; i < k; i++) {
		cin >> b[i];
		kek.insert(b[i]);
	}
	int ans = 1;
	for (int i = 0; i < k; i++) {
		kek.erase(b[i]);
		int x = where[b[i]];
		auto it = s.lower_bound(x);
		assert(it != s.end() && *it == x);
		int r = -1;
		int l = -1;
		if (it != s.end()) {
			it++;
			if (it != s.end()) {
				r = *it;
			}
			it--;
		}	
		if (it != s.begin()) {
			it--;
			l = *it;
		}
		if (r == -1 && l == -1) {
			ans = 0;
			break;
		}
		if (r == -1 || l == -1) {
			int x = max(l, r);
			if (kek.find(a[x]) != kek.end()) {
				ans = 0;
				break;
			}
			s.erase(x);
			continue;
		}
		if (kek.find(a[l]) != kek.end()) {
			if (kek.find(a[r]) != kek.end()) {
				ans = 0;
				break;
			}
			s.erase(r);
			continue;
		}
		if (kek.find(a[r]) != kek.end()) {
			s.erase(l);
			continue;
		}
		s.erase(l);
		ans = mul(ans, 2);
	}	
	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}