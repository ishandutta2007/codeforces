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
const int MAXN = 300228;


int n;
string s;
int kek[21];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	string s;
	cin >> s;
	n = sz(s);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int t = i;
		bool was = false;
		while (t < n && !was) {
			for (int f = t - 1; f >= i; f--) {
				if (f - (t - f) >= i && s[f] == s[t] && s[f - (t - f)] == s[f]) {
					was = true;
					break;
				}
			}
			if (was) {
				break;
			}
			t++;
		}
		ans += n - t;
	}
	cout << ans << endl;
}