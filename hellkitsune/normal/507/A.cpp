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
int a[100], ord[100];

bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    int cnt = n;
    REP(i, n) if (a[ord[i]] > k) {
        cnt = i;
        break;
    } else {
        k -= a[ord[i]];
    }
    cout << cnt << '\n';
    REP(i, cnt) cout << ord[i] + 1 << ' ';
    cout << '\n';
    return 0;
}