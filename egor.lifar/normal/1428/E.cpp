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
const int MAXN = 100228;


int n, k;
int a[MAXN];
int cur[MAXN];


ll get(ll x, ll cnt) {
	if (x <= cnt) {
		return x;
	}
	ll f = x / cnt;
	ll f1 = cnt - x % cnt;
	ll f2 = f + 1;
	ll f3 = x % cnt;
	return f * f * f1 + f2 * f2 * f3;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//read(FILENAME);
	cin >> n >> k;
	set<pair<ll, int> > s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cur[i] = 1;
		s.insert(mp(get(a[i], cur[i]) - get(a[i], cur[i] + 1), i));
	}
	for (int i = 0; i < k - n; i++) {
		auto d = *s.rbegin();
		s.erase(d);
		cur[d.second]++;
		s.insert(mp(get(a[d.second], cur[d.second]) - get(a[d.second], cur[d.second] + 1), d.second));
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += get(a[i], cur[i]);
	}
	cout << ans << '\n';
}