// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

typedef pair<int, int> PII;

const int N = 15;

int n, m, cnt[10], mc[N], md[N], mn[N], p1[N][N], p2[N][N];

PII a[N], b[N];

int inline chk() {
    int c = 0; int p;
    for (int i = 1; i < 10; i++) if (mn[i]) c++, p = i;
    if (c == 1) return p;
    bool o = 1;
    for (int i = 1; i <= n; i++) {
        if (mc[i] > 0) {
            if (p1[i][a[i].fi] && p1[i][a[i].se]) return -1;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (md[i] > 0) {
            if (p2[i][b[i].fi] && p2[i][b[i].se]) return -1;
        }
    }
    return 0;
}
 
int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i].fi), read(a[i].se);
        if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
    }
    for (int i = 1; i <= m; i++) {
        read(b[i].fi), read(b[i].se);
        if (b[i].fi > b[i].se) swap(b[i].fi, b[i].se);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i].fi == b[j].fi && a[i].se == b[j].se) continue;
            cnt[a[i].fi]++, cnt[b[j].fi]++, cnt[a[i].se]++, cnt[b[j].se]++;
            bool o = 0; int p = -1;
            for (int k = 0; k < 10; k++) {
                if (cnt[k] > 1) {
                    o = 1;
                    p = k;
                }
            }
            if (o) mc[i]++, md[j]++, mn[p]++, p1[i][p]++, p2[j][p]++;
            for (int k = 0; k < 10; k++) cnt[k] = 0;
        }
    }
    printf("%d\n", chk());
    return 0;
}