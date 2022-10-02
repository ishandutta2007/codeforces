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
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
const int MAXN = 2005;

int n, k;
string s[MAXN];
string c[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool can[MAXN][MAXN];
int d[MAXN][MAXN];


int get(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < sz(a); i++) {
        if (a[i] == '1' && b[i] == '0') {
            return -1;
        }
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    return cnt;
}


int val[11];
int pos[MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   // read(FILENAME);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            for (int f = 0; f < 10; f++) {
                int t = get(s[i], c[f]);
                if (t != -1) {
                    can[i][t] = true;
                    chkmax(d[i][t], f);
                }
            } 
        } else {
            for (int f = 0; f < 10; f++) {
                val[f] = get(s[i], c[f]);
            }
            for (int j = 0; j <= k; j++) {
                for (int f = 0; f < 10; f++) {
                    if (val[f] != -1) {
                        if (j >= val[f]) {
                            if (can[i + 1][j - val[f]]) {
                                can[i][j] = true;
                                chkmax(d[i][j], f);
                                if (d[i][j] == f) {
                                    pos[i][j] = j - val[f];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int cur = k;
    int i = 0;
    if (!can[i][cur]) {
        cout << -1 << '\n';
        return 0;
    }
    while (true) {
        cout << d[i][cur];
        if (i == n - 1) {
            break;
        }
        cur = pos[i][cur];
        i++;
    }
    cout << endl;
}