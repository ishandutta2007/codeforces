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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int t, k;
int d[100001];

const int MOD = 1e9 + 7;

inline int pMod(int x) {
    if (x >= MOD) return x - MOD;
    return x;
}

inline int mMod(int x) {
    if (x < 0) return x + MOD;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t >> k;
    d[0] = 1;
    for (int i = 1; i < 100001; ++i) {
        d[i] = d[i - 1];
        if (i >= k) d[i] = pMod(d[i] + d[i - k]);
    }
    for (int i = 1; i < 100001; ++i)
        d[i] = pMod(d[i] + d[i - 1]);
    REP(test, t) {
        int a, b;
        cin >> a >> b;
        int ans = mMod(d[b] - d[a - 1]);
        cout << ans << '\n';
    }
    return 0;
}