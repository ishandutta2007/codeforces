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
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 500008;

string s;
int dp[MAXN][27];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> s;
    for (int i = 0; i < sz(s); i++) {
        for (int j = 0; j < 26; j++) {
            if (i) {
                chkmax(dp[i][j], dp[i - 1][j]);
            }
        }
        int t = 0;
        for (int j = 0; j < s[i] - 'a'; j++) {
            chkmax(t, dp[i][j]);
        }
        chkmax(dp[i][s[i] - 'a'], t + 1);
        if (dp[i][s[i] - 'a'] >= 2) {
            cout << "Ann\n"; 
        } else {
            cout << "Mike\n";
        }
    }
    return 0; 
}