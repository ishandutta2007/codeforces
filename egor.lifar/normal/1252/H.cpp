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
const int MAXN = 16;



int n, k;
int a[MAXN];
int dp[66000][2005];
int b[299020];
int rk[202002];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    dp[0][0] = -2;
    int i, j;
    for (i = 0; i < (1 << n); i++) {
        for (j = sum; j >= 0; j--) {
            if (dp[i][j]) {
                for (int l = 0; l < n; l++) {
                    if (!(i >> l & 1)) {
                        dp[i | (1 << l)][j + a[l]] = l + 1;
                    }
                }
                if (j && j % k == 0) {
                    dp[i][j / k] = -1;
                }
            }   
        }
    }
    if (!dp[--i][j = 1]) {
        cout << "NO\n";
        return 0;
    }
    int z = 0, id = 0;
    for (;i;) {
        for (; dp[i][j] == -1; j *= k, z++);
        b[++id] = dp[i][j] - 1;
        rk[id] = z;
        i ^= 1 << b[id];
        b[id] = a[b[id]];
        j -= b[id];
    }
    cout << "YES\n";
    for (i = 1; i < n; i++) {
        int mx = 0, x = 0, y = 0;
        for (j = 1; j <= n; j++) {
            if (b[j] != -1 && rk[j] > mx) {
                mx = rk[j];
            }
        }
        for (j = 1; j <= n; j++) {
            if (b[j] != -1 && rk[j] == mx) {
                (x ? y: x) = j;
            }
        }
        cout << b[x] << ' ' << b[y] << '\n';
        b[x] += b[y];
        b[y] = -1; 
        for (; b[x] % k == 0; b[x] /= k, rk[x]--);
    }
    return 0;
}