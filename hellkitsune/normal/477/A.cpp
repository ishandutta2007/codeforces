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

int a, b;
LL ans = 0;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    int mult = (((LL)a * (a + 1)) / 2) % MOD;
    for (int m = 1; m < b; ++m) {
        ans += (LL)m * a;
        ans += mult * (((LL)m * b) % MOD);
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}