// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <iostream>
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
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
  
typedef int base;
typedef pair<base, base> point;

const string FILENAME = "input";

const int MAXN = 2e5;

int n;
long long v[MAXN];
long long t[MAXN];
long long pref1[MAXN];
long long ans[MAXN];

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		t[i] += t[i - 1];
	}
	t[n + 1] = 1e18;
 	for (int i = 1; i <= n; ++i) {
		pref1[0]--;
		pref1[i]++;
		v[i] += t[i - 1];
		auto it = upper_bound(t, t + (n + 2), v[i]);
		int j = it - t;	
		pref1[0]++;
		pref1[j]--;
		ans[j] += v[i] - t[j - 1];
	}
	for (int i = 1; i <= n; ++i) {
		pref1[i] += pref1[i - 1];
		ans[i] += pref1[i] * (t[i] - t[i - 1]);
		cout << ans[i] << ' ';
	}
	cout << endl;
}