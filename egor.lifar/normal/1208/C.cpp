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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";


int res[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  // read(FILENAME); 
    int n;
    cin >> n;
    if (n == 4) {
    	cout << "8 9 1 13 3 12 7 5 0 2 4 11 6 10 15 14\n";
    	exit(0);
    }
   	for (int i = 0; i < n / 2; i++) {
   		for (int j = 0; j < n / 2; j++) {
   			res[i][j] = i * (n / 2) + j;
   			res[i + n / 2][j] = i * (n / 2) + j;
   			res[i + n / 2][j + n / 2] = i * (n / 2) + j;
   			res[i][j + n / 2] = i * (n / 2) + j;
   		}
   	}
   	set<int> s;
   	for (int i = 0; i < n; i++) {
   		int t = 0;
   		for (int j = 0; j < n; j++) {
   			int mod = (i >= n / 2) * 2 + (j >= n / 2);
   			int is = i;
   			if (is >= n / 2) {
   				is -= n / 2;
   			}
   			int js = j;
   			if (js >= n / 2) {
   				js -= n / 2;
   			}
   			res[i][j] *= 4;
   			res[i][j] += (((is % n / 2) + (js % n / 2)) % 4 + mod) % 4;
   			cout << res[i][j] << ' ';
   			t ^= res[i][j];
   		}
   		s.insert(t);
   		cout << '\n';
   	}
   	for (int i = 0; i < n; i++) {
   		int t = 0;
   		for (int j = 0; j < n; j++) {
   			t ^= res[j][i];
   		}
   		s.insert(t);
   	}
   	assert(sz(s) == 1);
    return 0; 
}