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
const string FILENAME = "input";





long long gcd(long long a, long long b) {
	return (a == 0 ? b: gcd(b % a, a));
}

long long n, k, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n >> k >> a >> b;
	vector<long long> st;
	for (long long i = 1; i <= n; i++) {
		st.pb(1LL * (i - 1) * k + 1);
		//cout << 1LL * (i - 1) * k + 1 << endl;
	}
	vector<long long> pos;
	pos.pb(st[0] + a);
	pos.pb(st[0] - a + 1LL * n * k);
	vector<long long> kek;
	for (auto x: st) {
		long long as = x + b;
		if (as > 1LL * n * k) {
			as -= 1LL * n * k;
		}
		kek.pb(as);
	}
	for (auto x: st) {
		long long as = x - b;
		if (as <= 0) {
			as += 1LL * n * k;
		}
		kek.pb(as);
	}
	sort(all(kek));
	vector<long long> sts;
	for (auto x: pos) {
	//	cout << x << endl;
		for (auto y: kek) {
			long long l = (y >= x ? y - x: 1LL * n * k - x + y);
			if (l == 0) {
				l = 1LL * n * k;
			}
			//cout << y << endl;
			sts.pb(1LL * n * k / __gcd(l, 1LL * n * k));
		}
	}
	sort(all(sts));
	cout << sts[0] << ' ' << sts.back() << endl;
	return 0; 	
}