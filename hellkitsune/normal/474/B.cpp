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

int n, m;
int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];
    cin >> m;
    REP(i, m) {
        int x;
        cin >> x;
        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (a[mid] < x)
                lo = mid + 1;
            else
                hi = mid;
        }
        cout << lo + 1 << '\n';
    }
    return 0;
}