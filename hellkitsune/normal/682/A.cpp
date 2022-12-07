#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[5], b[5];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        ++a[i % 5];
    }
    for (int i = 1; i <= m; ++i) {
        ++b[i % 5];
    }
    LL ans = 0;
    REP(i, 5) REP(j, 5) if ((i + j) % 5 == 0) {
        ans += (LL)a[i] * b[j];
    }
    cout << ans << endl;
    return 0;
}