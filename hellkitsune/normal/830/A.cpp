#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, p;
int a[3000], b[3000];

bool solve(int mx) {
    int j = 0;
    forn(i, n) {
        while (j < k && abs(a[i] - b[j]) + abs(b[j]) > mx) {
            ++j;
        }
        if (j == k) {
            return false;
        }
        ++j;
    }
    return true;
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    forn(i, n) scanf("%d", a + i), a[i] -= p;
    forn(i, k) scanf("%d", b + i), b[i] -= p;
    sort(a, a + n);
    sort(b, b + k);
    int lo = 0, hi = int(2e9), mid;
    while (lo < hi) {
        mid = ((LL)lo + hi) / 2;
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
    return 0;
}