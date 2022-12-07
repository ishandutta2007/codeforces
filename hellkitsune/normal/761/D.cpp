#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, from, to;
int a[100000];
int b[100000];
int c[100000], ord[100000];

inline bool cmp(const int &lhs, const int &rhs) {
    return c[lhs] < c[rhs];
}

int main() {
    scanf("%d%d%d", &n, &from, &to);
    forn(i, n) {
        scanf("%d", a + i);
    }
    forn(i, n) {
        scanf("%d", c + i);
        --c[i];
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    int need = -int(2e9) - 123;
    forn(i, n) {
        int can = max(from, need + a[ord[i]] + 1);
        if (can > to) {
            cout << -1 << endl;
            return 0;
        }
        b[ord[i]] = can;
        need = can - a[ord[i]];
    }
    forn(i, n) {
        printf("%d ", b[i]);
    }
    puts("");
    return 0;
}