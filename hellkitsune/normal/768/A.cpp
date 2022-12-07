#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100005];

int main() {
    int mn, mx;
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    mn = mx = a[0];
    forn(i, n) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int ans = 0;
    forn(i, n) {
        if (a[i] != mn && a[i] != mx) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}