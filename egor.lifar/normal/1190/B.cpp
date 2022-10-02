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


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 100228;

int n;
int a[MAXN];
map<int, int> cnt;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (auto x: cnt) {
		if (x.second >= 3) {
			cout << "cslnb\n";
			exit(0);
		}
	}
	if (cnt[0] == n) {
		cout << "cslnb\n";
		exit(0);
	}
	int cnts = 0;
	for (auto x: cnt) {
		if (x.second >= 2) {
			cnts++;
		}
	}
	if (cnts >= 2) {
		cout << "cslnb\n";
		exit(0);
	}
	if (cnt[0] >= 2) {
		cout << "cslnb\n";
		exit(0);
	}
	for (auto x: cnt) {
		if (x.second >= 2) {
			if (cnt[x.first - 1] >= 1) {
				cout << "cslnb\n";
				exit(0);
			}
		}
	}
	long long sum = 0;
	long long sum1 = 0;
	for (int i = 0; i < n; i++) {
		sum += i;
		sum1 += a[i];
	}
	if (sum1 >= sum && (sum1 - sum) & 1) {
		cout << "sjfnb\n";
		exit(0);
	}
	cout << "cslnb\n";
	return 0;
}