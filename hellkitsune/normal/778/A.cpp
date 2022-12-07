#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char a[200005], b[200005];
int ord[200005];
int n, m;
bool del[200005];
char z[200005];
int len;

int main() {
    scanf("%s%s", a, b);
    n = strlen(a);
    m = strlen(b);
    forn(i, n) scanf("%d", ord + i), --ord[i];
    int lo = 0, hi = n - m, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        forn(i, n) del[i] = false;
        forn(i, mid) del[ord[i]] = true;
        int pos = 0;
        forn(i, n) if (!del[i]) {
            if (pos < m && a[i] == b[pos]) {
                ++pos;
            }
        }
        if (pos == m) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
    return 0;
}