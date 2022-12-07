#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;

LL st[1 << 18][10];
int sp[1 << 18][10];
int a[100000];
const int off = 1 << 17;

void stBuild() {
    forn(i, n) {
        int mul = 1;
        int x = a[i];
        while (x > 0) {
            int dig = x % 10;
            x /= 10;
            st[i + off][dig] += mul;
            mul *= 10;
        }
    }
    for (int i = off - 1; i >= 1; --i) {
        forn(j, 10) st[i][j] = st[2 * i][j] + st[2 * i + 1][j];
    }
    forn(i, 2 * off) {
        forn(j, 10) {
            sp[i][j] = j;
        }
    }
}

LL tmp[10];

inline void stPush(int v) {
    bool need = false;
    forn(i, 10) if (sp[v][i] != i) {
        need = true;
        break;
    }
    if (need) {
        for (int i = 2 * v; i <= 2 * v + 1; ++i) {
            forn(j, 10) {
                sp[i][j] = sp[v][sp[i][j]];
            }
            forn(j, 10) tmp[j] = 0;
            forn(j, 10) {
                tmp[sp[v][j]] += st[i][j];
            }
            forn(j, 10) {
                st[i][j] = tmp[j];
            }
        }
        forn(i, 10) {
            sp[v][i] = i;
        }
    }
}

int x, y;
void stUpdate(int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (l == L && r == R) {
        st[v][y] += st[v][x];
        st[v][x] = 0;
        forn(i, 10) if (sp[v][i] == x) {
            sp[v][i] = y;
        }
        return;
    }
    if (L != R) {
        stPush(v);
    }
    int mid = (L + R) >> 1;
    stUpdate(2 * v, L, mid, l, min(r, mid));
    stUpdate(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
    forn(i, 10) {
        st[v][i] = st[2 * v][i] + st[2 * v + 1][i];
    }
}

LL stGet(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (l == L && r == R) {
        LL res = 0;
        forn(i, 10) {
            res += i * st[v][i];
        }
        return res;
    }
    if (L != R) {
        stPush(v);
    }
    int mid = (L + R) >> 1;
    LL res = 0;
    res += stGet(2 * v, L, mid, l, min(r, mid));
    res += stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
    return res;
}

int DEB = 0;
mt19937 mt(123);

int main() {
    //freopen("input.txt", "r", stdin);
    if (DEB) {
        n = q = 100000;
        forn(i, n) a[i] = mt() % 999999999 + 1;
    } else {
        scanf("%d%d", &n, &q);
        forn(i, n) scanf("%d", a + i);
    }
    stBuild();
    forn(i, q) {
        int qt, from, to;
        if (DEB) {
            qt = mt() % 2 + 1;
            from = mt() % n;
            to = mt() % n;
            if (from > to) {
                swap(from, to);
            }
        } else {
            scanf("%d%d%d", &qt, &from, &to), --from, --to;
        }
        if (qt == 1) {
            if (DEB) {
                x = mt() % 10;
                y = mt() % 9 + 1;
            } else {
                scanf("%d%d", &x, &y);
            }
            if (x != y) {
                stUpdate(1, 0, off - 1, from, to);
            }
        } else {
            LL res = stGet(1, 0, off - 1, from, to);
            if (!DEB) {
                printf("%I64d\n", res);
            }
        }
    }
    return 0;
}