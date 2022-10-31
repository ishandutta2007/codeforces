#include<bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 4e5 + 100;
const int MOD = 1e9 + 9;
const int M = 239;

ll is[N], sum[N];
ll powers[N];
ll sumpowers[N];

int n, m, k;
char s[N];

void build(int v, int vl, int vr) {
    is[v] = -1;
    if (vr == vl + 1) {
        sum[v] = s[vl] - '0';
    } else {
        int mid = (vl + vr) / 2;
        build(v * 2 + 1, vl, mid);
        build(v * 2 + 2, mid, vr);
        sum[v] = (sum[v * 2 + 1] + sum[v * 2 + 2] * powers[mid - vl]) % MOD;
    }
}

void push(int v, int vl, int vr) {
    if (is[v] >= 0) {
        int mid = (vl + vr) / 2;
        is[v * 2 + 1] = is[v];
        is[v * 2 + 2] = is[v];
        sum[v * 2 + 1] = (sumpowers[mid - vl] * is[v]) % MOD;
        sum[v * 2 + 2] = (sumpowers[vr - mid] * is[v]) % MOD;
        is[v] = -1;
    }
}

void settree(int v, int vl, int vr, int l, int r, int c) {
    if (vr <= l || vl >= r) {
        return;
    }
    if (vl >= l && vr <= r) {
        is[v] = c;
        sum[v] = (c * sumpowers[vr - vl]) % MOD;
    } else {
        int mid = (vl + vr) / 2;
        push(v, vl, vr);
        settree(v * 2 + 1, vl, mid, l, r, c);
        settree(v * 2 + 2, mid, vr, l, r, c);
        sum[v] = (sum[v * 2 + 1] + sum[v * 2 + 2] * powers[mid - vl]) % MOD;
    }
}

ll get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || vl >= r) {
        return 0;
    }
    if (vl >= l && vr <= r) {
        return sum[v];
    } else {
        int mid = (vl + vr) / 2;
        push(v, vl, vr);
        return (get(v * 2 + 1, vl, mid, l, r) + powers[max(0, mid - max(vl, l))] * get(v * 2 + 2, mid, vr, l, r)) % MOD;
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    scanf(" %s", s + 1);
    powers[0] = 1;
    for (int i = 1; i < N; i++) {
        powers[i] = powers[i - 1] * M % MOD;
    }
    for (int i = 1; i < N; i++) {
        sumpowers[i] = (sumpowers[i - 1] + powers[i - 1]) % MOD;
    }
    build(0, 1, n + 1);
    for (int i = 0; i < m + k; i++) {
        int t, l, r, c;
        scanf("%d%d%d%d", &t, &l, &r, &c);
        if (t == 1) {
            settree(0, 1, n + 1, l, r + 1, c);
        } else {
            r++;
            if (l == r - c || get(0, 1, n + 1, l, r - c) == get(0, 1, n + 1, l + c, r)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}