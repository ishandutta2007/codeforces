#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n;
char s[3333];
int a[3333];
int b[33];
int to[3333];
int d[3333];

int main() {
    scanf("%d%s", &n, s);
    forn(i, n) {
        a[i] = int(s[i] - 'a');
    }
    forn(i, 26) {
        scanf("%d", b + i);
    }
    forn(i, n) {
        int &res = to[i] = i;
        int can = 3333;
        for (int j = i; j < n; ++j) {
            can = min(can, b[a[j]]);
            if (j - i + 1 > can) {
                break;
            }
            res = j + 1;
        }
    }
    memset(d, 0, sizeof d);
    d[0] = 1;
    forn(i, n) {
        for (int j = i + 1; j <= to[i]; ++j) {
            d[j] += d[i];
            if (d[j] >= MOD) {
                d[j] -= MOD;
            }
        }
    }
    printf("%d\n", d[n]);
    int mx = 0;
    forn(i, n) {
        mx = max(mx, to[i] - i);
    }
    printf("%d\n", mx);
    int best = 0;
    for (int i = 0; i < n; i = to[i]) {
        ++best;
    }
    cout << best << endl;
    return 0;
}