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
int a[2000], ans[2000];
int ord[2000];

bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] > a[rhs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    ans[ord[0]] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[ord[i]] == a[ord[i - 1]]) {
            ans[ord[i]] = ans[ord[i - 1]];
        } else {
            ans[ord[i]] = i + 1;
        }
    }
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}