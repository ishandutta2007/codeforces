// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5, L = 18;

int n, s[N];

char a[N];

// ST 

int inline cmp(int x, int y) {
    return s[x] < s[y] ? x : y;
}


int inline cmp2(int x, int y) {
    return s[x] > s[y] ? x : y;
}

struct ST{
    int g[N], f[N][L];
    void inline STPrework() {
        g[0] = -1;
        for (int i = 1; i <= 2 * n + 1; i++) 
            f[i][0] = i, g[i] = g[i >> 1] + 1;
        for (int j = 1; j <= g[2 * n + 1]; j++)
            for (int i = 0; i + (1 << j) - 1 <= 2 * n; i++) {
                f[i][j] = cmp(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
             }
    }

    int inline query(int l, int r) {
        int k = g[r - l + 1];
        return cmp(f[l][k], f[r - (1 << k) + 1][k]);
    }
} st;

struct ST2{
    int g[N], f[N][L];
    void inline STPrework() {
        g[0] = -1;
        for (int i = 1; i <= 2 * n + 1; i++) 
            f[i][0] = i, g[i] = g[i >> 1] + 1;
        for (int j = 1; j <= g[2 * n + 1]; j++)
            for (int i = 0; i + (1 << j) - 1 <= 2 * n; i++) {
                f[i][j] = cmp2(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
    }

    int inline query(int l, int r) {
        if (l > r) return -1;
        int k = g[r - l + 1];
        return cmp2(f[l][k], f[r - (1 << k) + 1][k]);
    }
} mt;

bool ok;

int pr = -1, sf = -1;

void solve(int l, int r) {
    if (l > r || ok) return;
    int p = mt.query(l, r);
    if (!ok) {
        int L = mt.query(l, min(pr - 1, p));
        int R = mt.query(max(sf + 1, p) , r);
        if (L != -1 && R != -1 && s[L] + s[R] >= s[p]) {
            ok = 1;
            puts("1");
            printf("%d %d\n", L + 1, R);
            return;
        } 
    }
    solve(l, p - 1);
    if (ok) return;
    solve(p + 1, r);
}

void work() {
    bool o0 = 1;
    pr = sf = -1;
    for (int i = 1; i <= 2 * n; i++) {
        if (s[i] < 0) {
            o0 = 0;
            if (pr == -1) pr = i;
            sf = i;
        }
    }
    if (o0) {
        puts("0");
        return;
    }
    ok = 0;
    solve(0, 2 * n);
    if (ok) return;
    puts("2");
    int mx = 0, p = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (chkMax(mx, s[i])) {
            p = i;
        }
    }
    printf("%d %d\n", 1, p);
    printf("%d %d\n", p + 1, 2 * n);
}

int main() {
    int T; read(T);
    while (T--) {
        read(n); scanf("%s", a + 1);
        for (int i = 1; i <= 2 * n; i++) {
            s[i] = s[i - 1] + (a[i] == '(' ? 1 : -1);
        }
        st.STPrework();
        mt.STPrework();
        work();
    }
    return 0;
}