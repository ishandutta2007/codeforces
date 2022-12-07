#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, d;
int a[105][105] = {};

const int mod = 1e9 + 7;

int main() {
    cin >> n >> k >> d;
    a[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= min(i, k); ++j)
            for (int p = i - j; p < i; ++p) {
                int dif = i - p;
                if (dif == j) for (int q = 0; q <= dif; ++q)
                    a[i][j] = (a[i][j] + a[p][q]) % mod;
                else
                    a[i][j] = (a[i][j] + a[p][j]) % mod;
            }
    int ans = 0;
    for (int i = d; i <= n; ++i)
        ans = (ans + a[n][i]) % mod;
    cout << ans << endl;
    return 0;
}