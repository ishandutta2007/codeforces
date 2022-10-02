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
const int MAXN = 100228;


int n;
int a[MAXN];
int id[MAXN];
bool bad[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n;
	int uk = 0;
	for (int i = 2; i <= n; i++) {
		if (!bad[i]) {
			uk++;
			id[i] = uk;
			for (int j = i; j <= n; j += i) {
				bad[j] = true;
			}
 		}
	}
	for (int i = 2; i <= n; i++) {
		int cur = i;
		int a = 2;
		int cnt = 0;
		int res = 0;
		while (a * a <= cur) {
			if (cur % a == 0) {
				while (cur % a == 0) {
					cur /= a;
				}
				cnt++;
				chkmax(res, a);
			}
			a++;
  		}
  		if (cur != 1) {
  			cnt++;
  			chkmax(res, cur);
  		}	
  		cout << id[res] << ' ';
	}		
	cout << endl;
	return 0;
}