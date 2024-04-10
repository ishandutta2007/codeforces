#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        int pos = n - mid;
        bool ok = true;
        forn(i, mid) {
            if (a[i] > b[pos + i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    printf("%d\n", n - lo);

    lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        int pos = n - mid;
        bool ok = true;
        forn(i, mid) {
            if (a[i] >= b[pos + i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    printf("%d\n", lo);
    return 0;
}