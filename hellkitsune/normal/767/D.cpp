#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int a[1000005];
int b[1000005];
PII p[1000005];

bool solve(int from) {
    int ind = 0;
    int day = 0, num = 0;
    while (ind < n || from < m) {
        if (ind < n && (from == m || a[ind] < b[from])) {
            if (a[ind] < day) {
                return false;
            }
            ++ind;
        } else {
            if (b[from] < day) {
                return false;
            }
            ++from;
        }
        if (++num == k) {
            num = 0;
            ++day;
        }
    }
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) scanf("%d", a + i);
    forn(i, m) scanf("%d", b + i);
    sort(a, a + n);
    forn(i, m) p[i] = mp(b[i], i + 1);
    sort(p, p + m);
    forn(i, m) b[i] = p[i].first;
    int lo = 0, hi = m + 1;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << m - lo << endl;
    for (int i = lo; i < m; ++i) {
        printf("%d ", p[i].second);
    }
    if (lo < m) {
        puts("");
    }
    return 0;
}