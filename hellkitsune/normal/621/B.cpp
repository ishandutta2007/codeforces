#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int cnt[5000] = {}, cnt2[5000] = {};

int main() {
    scanf("%d", &n);
    LL ans = 0;
    REP(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++cnt[x + y];
        ++cnt2[2000 + x - y];
    }
    REP(i, 5000) {
        int x = cnt[i];
        ans += x * (x - 1) / 2;
        x = cnt2[i];
        ans += x * (x - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}