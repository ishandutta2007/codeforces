#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[22], b[22];
int ord[22];

inline bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) forn(j, i) if (a[i] == a[j]) {
        cout << -1 << endl;
        return 0;
    }
    forn(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    forn(i, n) b[ord[(i + 1) % n]] = a[ord[i]];
    forn(i, n) printf("%d ", b[i]);
    puts("");
    return 0;
}