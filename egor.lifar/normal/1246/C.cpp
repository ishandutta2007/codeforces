
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
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 2228;
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int n, m;
string s[MAXN];
int dp[MAXN][MAXN][2];
int f[MAXN][MAXN][2];
int add[MAXN][MAXN][2];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (s[i][j] == 'R') {

            } else {
                cnt++;
            }
            f[i][j][0] = cnt;
        }
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[j][i] == 'R') {

            } else {
                cnt++;
            }
            f[j][i][1] = cnt;
        }
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int t = 0; t < 2; t++) {
                add[i][j][t] = sum(add[i][j][t], (t == 0 ? (j >= 1 ? add[i][j - 1][t]: 0): (i >= 1 ? add[i - 1][j][t]: 0)));
                dp[i][j][t] = sum(dp[i][j][t], add[i][j][t]);
                if (t == 1) {
                    int g = f[i][j + 1][0];
                    if (g >= 1) {
                        add[i][j + 1][0] = sum(add[i][j + 1][0], dp[i][j][t]);
                        add[i][j + g + 1][0] = sum(add[i][j + g + 1][0], (Mod - dp[i][j][t]) % Mod);
                    }   
                } else {
                    int g = f[i + 1][j][1];
                    if (g >= 1) {
                        add[i + 1][j][1] = sum(add[i + 1][j][1], dp[i][j][t]);
                        add[i + 1 + g][j][1] = sum(add[i + 1 + g][j][1], (Mod - dp[i][j][t]) % Mod);
                    }
                }
            }       
        }
    }
    if (n == 1 && m == 1) {
        cout << 1 << '\n';
        return 0;
    }
    cout << sum(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]) << '\n';
	return 0;
}