#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int mn = 1e9 + 111;
LL ans = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        ans += x;
        if (x & 1) mn = min(mn, x);
    }
    if (ans & 1) ans -= mn;
    cout << ans << endl;
    return 0;
}