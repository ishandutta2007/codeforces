#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
int a[100000];
vector<int> v;

int binPow(LL a, int b, int mod) {
    LL res = 1;
    bool aa = a >= mod;
    bool rr = res >= mod;
    while (b) {
        if (b & 1) {
            if (aa || res * a >= mod) {
                rr = true;
            }
            res = res * a % mod;
        }
        b >>= 1;
        if (a * a >= mod) {
            aa = true;
        }
        if (b) a = a * a % mod;
    }
    return (int)res + (rr ? mod : 0);
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%d", a + i);
    v.pb(m);
    while (v.back() != 1) {
        int cur = v.back();
        int nx = 1;
        for (int i = 2; i * i <= cur; ++i) {
            bool ft = true;
            while (cur % i == 0) {
                cur /= i;
                if (ft) nx *= i - 1;
                else nx *= i;
                ft = false;
            }
        }
        if (cur > 1) {
            nx *= cur - 1;
        }
        v.pb(nx);
    }
//    for (int x : v) cerr << x << ' ';
//    cerr << endl;
    scanf("%d", &q);
    forn(_, q) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        to = min(to, from + (int)v.size());
        int lst = a[to];
        while (to > from) {
            lst = binPow(a[to - 1], lst, v[to - 1 - from]);
            --to;
        }
        lst %= m;
        printf("%d\n", lst);
    }
    return 0;
}