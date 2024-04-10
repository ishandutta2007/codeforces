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
const long long MAXVAL = (1LL << 32) - 1;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	int l;
	cin >> l;
	vector<pair<int, long long > > g;
	long long cur = 0;
	for (int i = 0; i < l; i++) {
		string s;
		cin >> s;
		if (s == "for") {
			int x;
			cin >> x;
			g.pb({x, cur});
			cur = 0;
		} else {
			if (s == "end") {
				auto z = g.back();
				g.pop_back();
				long long kek = z.second;
				cur *= z.first;
				kek += cur;
				if (kek > MAXVAL) {
					cout << "OVERFLOW!!!\n";
					return 0;
				}
				cur = kek;
			} else {
				cur++;
				if (cur > MAXVAL) {
					cout << "OVERFLOW!!!\n";
					return 0;
				}
			}
		}
	}
	cout << cur << endl;
}