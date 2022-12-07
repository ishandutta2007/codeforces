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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[11111];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    ++n;
    for (int i = 2; i < (1 << n); ++i) cin >> a[i];
    LL ans = 0;
    for (int i = (1 << n) - 2; i >= 2; i -= 2) {
        ans += abs(a[i] - a[i + 1]);
        a[i / 2] += max(a[i], a[i + 1]);
    }
    cout << ans << endl;
    return 0;
}