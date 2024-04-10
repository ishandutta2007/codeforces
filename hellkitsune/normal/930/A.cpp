#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int p[100005], h[100005], cnt[100005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", p + i), --p[i];
    }
    h[0] = 0;
    ++cnt[0];
    for (int i = 1; i < n; ++i) {
        h[i] = h[p[i]] + 1;
        ++cnt[h[i]];
    }
    int ans = 0;
    forn(i, 100005) ans += cnt[i] & 1;
    cout << ans << endl;
    return 0;
}