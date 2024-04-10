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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //   read(FILENAME);	
   	int t;
   	cin >> t;
   	while (t--) {
   		int n;
   		cin >> n;
   		if (n < 4) {
   			cout << -1 << '\n';
   			continue;
   		}
   		vector<int> res;
   		while (n >= 8) {
   			res.pb(n - 1);
   			res.pb(n - 3);
   			res.pb(n);
   			res.pb(n - 2);
   			n -= 4;
   		}
   		if (n == 4) {
   			res.pb(3);
   			res.pb(1);
   			res.pb(4);
   			res.pb(2);
   		} else if (n == 5) {
   			res.pb(5);
   			res.pb(2);
   			res.pb(4);
   			res.pb(1);
   			res.pb(3);
   		} else if (n == 6) {
   			res.pb(5);
   			res.pb(3);
   			res.pb(6);
   			res.pb(2);
   			res.pb(4);
   			res.pb(1);
   		} else if (n == 7) {
   			res.pb(7);
   			res.pb(5);
   			res.pb(2);
   			res.pb(6);
   			res.pb(4);
   			res.pb(1);
   			res.pb(3);
   		}
   		for (auto x: res) {
   			cout << x << ' ';
   		}
   		cout << '\n';
   	}
}