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

int n, h, a[2002];
int d[2002][2] = {};

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > h) {
            cout << "0\n";
            return 0;
        }
        a[i] = h - a[i];
    }
    int lst = -1;
    a[0] = a[n + 1] = 0;
    for (int i = 0; i <= n; ++i) if (abs(a[i + 1] - a[i]) > 1) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) if (a[i] == 1) lst = i;
    if (lst == -1) {
        cout << "1\n";
        return 0;
    }
    d[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            d[i][0] = (d[i - 1][1] + d[i - 1][0]) % MOD;
        } else if (a[i] > a[i - 1]) {
            d[i][0] = d[i - 1][0];
        } else {
            d[i][0] = d[i - 1][1];
        }
        d[i][1] = (d[i][0] * (LL)a[i]) % MOD;
    }
    cout << d[lst][1] << endl;
    return 0;
}