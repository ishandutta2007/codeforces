#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int mod, n, nn;
int a[200005];
int b[200005], c[200005];

bool solve(int dif) {
    int save = n;
    n = nn;
    forn(i, n) {
        a[i] = c[i];
    }
    int x = a[0];
    while (true) {
        x -= dif;
        if (x < 0) {
            x += mod;
        }
        int ind = int(lower_bound(a, a + n, x) - a);
        if (ind == n || a[ind] != x) {
            x += dif;
            if (x >= mod) {
                x -= mod;
            }
            break;
        }
    }

    int cnt = 1;
    int y = x;
    while (true) {
        y += dif;
        if (y >= mod) {
            y -= mod;
        }
        int ind = int(lower_bound(a, a + n, y) - a);
        if (ind == n || a[ind] != y) {
            break;
        }
        if (++cnt == n) {
            break;
        }
    }

    if (cnt == n) {
        printf("%d %d\n", x, dif);
        return true;
    }
    n = save;
    forn(i, n) {
        a[i] = b[i];
    }
    return false;
}

int main() {
    scanf("%d%d", &mod, &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
    if (n == 1) {
        printf("%d %d\n", a[0], 0);
        return 0;
    }

//    mod = 200009;
//    n = 100000;
//    int x = 12345;
//    forn(i, n) {
//        a[i] = x;
//        x = (x + 54321) % mod;
//    }

    sort(a, a + n);
    bool bad = false;
    if (n * 2 > mod && n != mod && n != mod - 1) {
        bad = true;
        int cnt = 0;
        forn(i, mod) {
            int ind = int(lower_bound(a, a + n, i) - a);
            if (ind == n || a[ind] != i) {
                b[cnt++] = i;
            }
        }
        forn(i, n) {
            c[i] = a[i];
        }
        nn = n;
        n = cnt;
        forn(i, n) {
            a[i] = b[i];
        }
    }

//    cerr << n << ' ';
//    forn(i, n) {
//        cerr << a[i] << ' ';
//    }
//    cerr << endl;

    for (int i = 1; i < n; ++i) {
        int dif = a[i] - a[0];
        int cnt = 1;
        int x = a[0];
        while (true) {
            x += dif;
            if (x >= mod) {
                x -= mod;
            }
            int ind = int(lower_bound(a, a + n, x) - a);
            if (ind == n || a[ind] != x) {
                break;
            }
            if (++cnt == n) {
                if (bad) {
                    if (solve(dif)) {
                        return 0;
                    }
                } else {
                    printf("%d %d\n", a[0], dif);
                    return 0;
                }
                break;
            }
        }
        if (cnt == n) {
            continue;
        }
        x = a[0];
        while (true) {
            x -= dif;
            if (x < 0) {
                x += mod;
            }
            int ind = int(lower_bound(a, a + n, x) - a);
            if (ind == n || a[ind] != x) {
                break;
            }
            if (++cnt == n) {
                if (bad) {
                    if (solve(dif)) {
                        return 0;
                    }
                } else {
                    printf("%d %d\n", x, dif);
                    return 0;
                }
                break;
            }
        }
    }
    printf("-1\n");
    return 0;
}