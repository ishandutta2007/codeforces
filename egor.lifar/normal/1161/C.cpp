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
#define rank rank228
const string FILENAME = "input";
const int MAXN = 58;


int n;
int a[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 2) {
		int f = a[0] ^ a[1];
		if (f != 0) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	} else {
		int s = 0;
		int f = 1e9;
		for (int i = 0; i < n; i++) {
			chkmin(f, a[i]);
		}
		for (int i = 0; i < n; i++) {
			a[i] -= f;
		}
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				s++;
			}
		}
		if (s < n / 2) {
			cout << "Bob\n";
			return 0;
		}
		cout << "Alice\n";
		return 0;
	}
	return 0; 	
}