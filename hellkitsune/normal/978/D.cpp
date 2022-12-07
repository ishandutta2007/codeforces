#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
int a[100000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    int ans = INF;
    for (int p = -1; p <= 1; ++p) {
        for (int q = -1; q <= 1; ++q) {
            int cnt = abs(p) + abs(q);
            LL last = a[1] + q;
            LL dif = (a[1] + q) - (a[0] + p);
            bool ok = true;
            for (int i = 2; i < n; ++i) {
                last += dif;
                if (abs(last - a[i]) > 1) {
                    ok = false;
                    break;
                }
                cnt += abs(last - a[i]);
            }
            if (ok) {
                ans = min(ans, cnt);
            }
        }
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}