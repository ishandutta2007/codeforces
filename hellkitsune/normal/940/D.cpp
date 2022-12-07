#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
int a[100000], b[100000];
char s[100005];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    scanf("%s", s);
    forn(i, n) b[i] = s[i] - '0';
    int l = -INF, r = INF;
    for (int i = 4; i < n; ++i) {
        int mx = a[i];
        int mn = a[i];
        forn(j, 5) {
            mx = max(mx, a[i - j]);
            mn = min(mn, a[i - j]);
        }
        bool all1 = b[i - 1] == 1 && b[i - 2] == 1 && b[i - 3] == 1 && b[i - 4] == 1;
        bool all0 = b[i - 1] == 0 && b[i - 2] == 0 && b[i - 3] == 0 && b[i - 4] == 0;
        int res = b[i - 1];
        if (mn > r && all1) {
            res = 0;
        }
        if (mx < l && all0) {
            res = 1;
        }
        if (res != b[i]) {
            if (b[i] == 0) {
                assert(all1);
                r = mn - 1;
            } else {
                assert(all0);
                l = mx + 1;
            }
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}