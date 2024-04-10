#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[200000], rev[200000];
LL ans = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    REP(i, n) rev[a[i]] = i;
    REP(i, n - 1) {
        ans += abs(rev[i] - rev[i + 1]);
    }
    cout << ans << endl;
    return 0;
}