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

int n, x;
int a[100], b[100];
bool f[1001];

const int INF = 1e9;
int ans = INF;

int main() {
    cin >> n >> x;
    REP(i, n) cin >> a[i] >> b[i];
    REP(i, n) if (a[i] > b[i]) swap(a[i], b[i]);
    REP(i, 1001) f[i] = true;
    REP(i, n) {
        REP(j, a[i]) f[j] = false;
        for (int j = b[i] + 1; j <= 1000; ++j) f[j] = false;
    }
    REP(i, 1001) if (f[i])
        ans = min(ans, abs(x - i));
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}