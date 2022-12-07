#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100005];
int b[100005];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) b[i] = a[i] + 1;
    for (int i = n - 1; i > 0; --i) {
        b[i - 1] = max(b[i - 1], b[i] - 1);
    }
    forn(i, n - 1) {
        b[i + 1] = max(b[i + 1], b[i]);
    }
    LL ans = 0;
    forn(i, n) {
        ans += b[i] - a[i] - 1;
    }
    cout << ans << endl;
    return 0;
}