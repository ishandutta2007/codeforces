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

int n, k;
int a[100];
vector<int> ans[100];
int ord[100];

bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    int curC = 1;
    int cnt = a[ord[0]];
    if (cnt > 0) {
        REP(i, n) REP(j, cnt)
            ans[i].pb(curC);
    }
    REP(i, n) a[i] -= cnt;
    for (int i = 1; i < n; ++i) {
        int ind = ord[i];
        while (a[ind] > 0) {
            for (int j = i; j < n; ++j) {
                ans[ord[j]].pb(curC);
                --a[ord[j]];
            }
            ++curC;
        }
    }
    if (curC > k + 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    REP(i, n) {
        for (int x : ans[i]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}