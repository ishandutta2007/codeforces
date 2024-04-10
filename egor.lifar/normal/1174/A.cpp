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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 2001;

int n;
int a[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + 2 * n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	if (sum - ans != ans) {
		for (int i = 0; i < 2 * n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return 0;
	}
	cout << -1 << endl;
	return 0;
}