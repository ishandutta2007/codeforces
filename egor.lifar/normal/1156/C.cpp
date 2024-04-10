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
const int MAXN = 200228;

int n, z;
int x[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n >> z;
 	for (int i = 0; i < n; i++) {
 		cin >> x[i];
 	}
 	sort(x, x + n);
 	int l = 0;
 	int r = n / 2;
 	while (l < r) {
 		int mid = (l + r + 1) >> 1;
 		bool bad = false;
 		for (int i = 0; i < mid; i++) {
 			if (x[n - mid + i] - x[i] < z) {
 				bad = true;
 				break;
 			}
 		}
 		if (!bad) {
 			l = mid;
 		} else {
 			r = mid - 1;
 		}
 	}
 	cout << l << '\n';
	return 0; 	
}