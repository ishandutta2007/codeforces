#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, w;
int a[100], ord[100], b[100];

inline bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] > a[rhs];
}

int main() {
    scanf("%d%d", &n, &w);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) {
        b[i] = (a[i] + 1) / 2;
        w -= b[i];
    }
    if (w < 0) {
        cout << -1 << endl;
        return 0;
    }
    forn(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    forn(ii, n) {
        int i = ord[ii];
        int can = min(w, a[i] - b[i]);
        w -= can;
        b[i] += can;
    }
    assert(w == 0);
    forn(i, n) {
        printf("%d ", b[i]);
    }
    puts("");
    return 0;
}