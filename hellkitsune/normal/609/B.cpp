#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int cnt[10] = {};

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int x;
        scanf("%d", &x), --x;
        ++cnt[x];
    }
    LL ans = (LL)n * (n - 1) / 2;
    REP(i, m) {
        ans -= (LL)cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}