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

int d[500000], e, e2;
int n;
const int MOD = 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    n >>= 1;
    d[0] = 1;
    int tmp = 4;
    for (int i = 1; i < n; ++i) {
        d[i] = (d[i - 1] + tmp) % MOD;
        tmp = (tmp << 1) % MOD;
    }
    for (int i = 1; i < n; ++i) {
        d[i] = ((LL)d[i] * d[i - 1]) % MOD;
    }
    e = 1;
    for (int i = 1; i < n; ++i) {
        e = (e + 4ll * d[i - 1]) % MOD;
    }
    e2 = ((LL)e * e) % MOD;
    cout << (4 + 4ll * e + 2ll * e2) % MOD << endl;
    return 0;
}