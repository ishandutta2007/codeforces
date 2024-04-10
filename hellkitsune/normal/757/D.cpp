#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[111];
int a[111];
int d[77][1 << 20] = {};
int nx[111];
int ans = 0;

const int MOD = int(1e9) + 7;

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%s", &n, s);
    forn(i, n) {
        a[i] = int(s[i] - '0');
    }
    forn(i, n + 1) {
        nx[i] = i;
        while (nx[i] < n && a[nx[i]] == 0) {
            ++nx[i];
        }
    }
    int from = 0;
    for (int i = nx[0]; i < n; i = nx[i + 1]) {
        d[i][0] = i - from + 1;
        from = i + 1;
    }
    for (int i = nx[0]; i < n; ++i) {
        forn(mask, 1 << 20) {
            if (d[i][mask] == 0) {
                continue;
            }
            int val = 0;
            for (int j = i; j < n; ++j) {
                val = (val << 1) | a[j];
                if (val > 20) {
                    break;
                }
                add(d[nx[j + 1]][mask | (1 << (val - 1))], d[i][mask]);
            }
        }
    }
    for (int mask = 1; mask < (1 << 20); ++mask) {
        bool ok = true;
        forn(i, 22) {
            int a = mask & (1 << i);
            int b = mask & (2 << i);
            if (a == 0 && b != 0) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        //cerr << mask << endl;
        forn(j, n + 1) {
            add(ans, d[j][mask]);
        }
    }
    cout << ans << endl;
    return 0;
}