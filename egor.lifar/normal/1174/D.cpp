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
int x;
int a[MAXN];
bool used[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n >> x;
	vector<int> g;
	for (int i = 1; i < (1 << n); i++) {
		if (!used[i] && i != x) {
			g.pb(i);
			used[i ^ x] = true;
			//cout << (i ^ x) << endl;
		}
	}
	cout << sz(g) << '\n';
	int last = 0;
	for (auto x: g) {
		cout << (x ^ last) << ' ';
		last = x;
	}
	cout << '\n';
	return 0;
}