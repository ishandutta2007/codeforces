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
#include <complex>


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
const int MAXN = 100229;



int n, d, m;
int a[MAXN];
ll pref[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> d >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		pref[i] = (a[i] <= m ? a[i]: 0);
		if (i) {
			pref[i] += pref[i - 1];
		}
	}
	ll ans = pref[n - 1];
	ll add = 0;
	ll cnt = 0;
	ll cntk = 0;
	ll cntk1 = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > m) {
			cntk++;
		} else {
			cntk1++;
		}
	}
	ll cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= m) {
			break;
		} 
		cnt++;
		cntk--;
		cur += a[i];
		ll needs = (ll)(cnt - 1) * d;
		if (needs > cntk + cntk1) {
			break;
		}
		ll fs = min(needs, cntk);
		needs -= fs;
		chkmax(ans, cur + (needs ? -pref[needs - 1]: 0) + pref[n - 1]);
	}
	cout << ans << '\n';
}