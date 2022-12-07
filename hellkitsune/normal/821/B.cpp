#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL ans = 0;
LL m, b;

int main() {
    cin >> m >> b;
    LL w = 0;
    for (LL h = b; h >= 0; --h) {
        ans = max(ans, w * (w + 1) / 2 * (h + 1) + h * (h + 1) / 2 * (w + 1));
        w += m;
    }
    cout << ans << endl;
    return 0;
}