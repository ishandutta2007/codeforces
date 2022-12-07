#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000], b[100000], ord[100000];
LL aa = 0, bb = 0;
int c[100000] = {};

inline bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] > a[rhs];
}

inline bool cmp2(const int &lhs, const int &rhs) {
    return b[lhs] > b[rhs];
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", b + i);
    forn(i, n) aa += a[i];
    forn(i, n) bb += b[i];
    aa = aa / 2;
    bb = bb / 2;
    int can = n / 2 + 1;
    forn(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    forn(i, can) {
        aa -= a[ord[i]];
        bb -= b[ord[i]];
        c[ord[i]] = 1;
    }
    assert(aa < 0);
    if (bb < 0) {
        printf("%d\n", can);
        forn(i, can) printf("%d ", ord[i] + 1);
        puts("");
        return 0;
    }
    sort(ord, ord + n, cmp2);
    int j = 0;
    forn(i, n) {
        if (c[ord[i]] != 0) {
            c[ord[i]] = 2;
            continue;
        }
        while (c[j] != 1) ++j;
        aa += a[j];
        bb += b[j];
        c[j] = 0;
        aa -= a[ord[i]];
        bb -= b[ord[i]];
        c[ord[i]] = 2;
        if (aa >= 0) {
            forn(i, n) c[i] = (c[i] == 0 ? 1 : 0);
            c[j] = 1;
            c[ord[i]] = 1;
            int sum = 0;
            forn(i, n) sum += c[i];
            printf("%d\n", sum);
            forn(i, n) if (c[i]) printf("%d ", i + 1);
            puts("");
            return 0;
        }
        if (bb < 0) {
            int sum = 0;
            forn(i, n) sum += c[i] > 0;
            printf("%d\n", sum);
            forn(i, n) if (c[i]) printf("%d ", i + 1);
            puts("");
            return 0;
        }
    }
    return 0;
}