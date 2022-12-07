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

int n;
int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    int sum = 0;
    REP(i, n) sum += a[i];
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 3;
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];
    LL ans = 0;
    int cnt = 0;
    REP(i, n - 1) {
        if (a[i] == sum * 2) ans += cnt;
        if (a[i] == sum) ++cnt;
    }
    cout << ans << endl;
    return 0;
}