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

int n;
int a[300000];
LL sum[300000];
LL ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }
    sort(a, a + n);
    sum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
        sum[i] = sum[i + 1] + a[i];
    for (int i = 0; i < n - 2; ++i)
        ans += sum[i] + a[i];
    ans += 2 * (a[n - 1] + a[n - 2]);
    cout << ans << '\n';
    return 0;
}