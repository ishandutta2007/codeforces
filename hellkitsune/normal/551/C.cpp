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

int n, m;
int a[100001];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    LL lo = 1, hi = 1e15, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        int stu = m;
        LL rem = 0;
        bool ok = true;
        for (int i = n; i >= 1; --i) if (a[i]) {
            if (mid <= i) {
                ok = false;
                break;
            }
            if (a[i] <= rem) {
                rem -= a[i];
                continue;
            }
            int t = a[i] - rem;
            LL cnt = (t + mid - i - 1) / (mid - i);
            if (cnt > stu) {
                ok = false;
                break;
            }
            stu -= cnt;
            rem = cnt * (mid - i) - t;
        }
        if (ok) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
    return 0;
}