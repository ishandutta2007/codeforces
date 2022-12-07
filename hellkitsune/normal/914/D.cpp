#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int n;
int a[500000];
int st[1 << 20];
const int OFF = 1 << 19;

void stBuild() {
    forn(i, n) st[OFF + i] = a[i];
    for (int i = OFF - 1; i >= 1; --i) {
        st[i] = gcd(st[2 * i], st[2 * i + 1]);
    }
}

void stAssign(int ind, int val) {
    ind += OFF;
    st[ind] = val;
    for (ind >>= 1; ind >= 1; ind >>= 1) {
        st[ind] = gcd(st[2 * ind], st[2 * ind + 1]);
    }
}

int cval, res;
void stCheck(int v, int L, int R, int l, int r) {
    if (l > r) return;
    int mid = (L + R) >> 1;
    if (l == L && r == R) {
        if (st[v] % cval == 0) {
            return;
        }
        if (L == R) {
            ++res;
            return;
        }
        if (st[2 * v] % cval != 0) {
            stCheck(2 * v, L, mid, L, mid);
            if (res > 1) return;
        }
        if (st[2 * v + 1] % cval != 0) {
            stCheck(2 * v + 1, mid + 1, R, mid + 1, R);
        }
        return;
    }
    stCheck(2 * v, L, mid, l, min(r, mid));
    if (res > 1) return;
    stCheck(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    stBuild();
    int q;
    scanf("%d", &q);
    forn(_, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x), --l, --r;
            cval = x;
            res = 0;
            stCheck(1, 0, OFF - 1, l, r);
            if (res < 2) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            int ind, y;
            scanf("%d%d", &ind, &y), --ind;
            stAssign(ind, y);
        }
    }
    return 0;
}