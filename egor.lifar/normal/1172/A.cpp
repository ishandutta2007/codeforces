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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 1000228;


int n;
int a[MAXN];
int b[MAXN];
bool have[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//read("input");
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		have[a[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) {
			bool bad= false;
			for (int j = i; j < n; j++) {
				if (b[j] != j - i + 1) {
					bad = true;
					break;
				}
			}
			if (!bad) {
				cnt = n - i;
			}
		}
	}
	if (cnt == n) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	int uk = n;
	bool was = false;
	bool wasp = false;
	if (cnt != 0) {
		wasp = true;
	}
	for (int i = 0; i < 3 * n; i++) {
		
		ans++;
		if (have[cnt + 1]) {
			uk++; 
			cnt++;
		} else {
			if (was || !wasp) {

			} else {
				cnt = 0;
				was = true;
			}
		}have[b[i]] = true;
	//	cout << b[i] << endl;
		if (cnt == n) {
			cout << ans << endl;
			return 0;
		}
	}
}