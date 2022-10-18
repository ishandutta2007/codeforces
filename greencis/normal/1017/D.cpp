#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, q, k, w[25], cnt[5005];
int precalc[5005];
int ans[5005][105];
char s[25];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    for (int i = 1 << n; i--; )
        for (int j = 0; j < n; ++j)
            if ((i >> j) & 1)
                precalc[i] += w[j];
    while (m--) {
        cin >> s;
        reverse(s, s + n);
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur = cur * 2 + (s[i] - '0');
        ++cnt[cur];
    }

    for (int i = 1 << n; i--; ) {
        for (int j = 1 << n; j--; ) {
            int mask = i ^ j ^ ((1 << n) - 1);
            if (precalc[mask] <= 100)
                ans[i][precalc[mask]] += cnt[j];
        }
    }

    for (int i = 1 << n; i--; )
        for (int j = 0; j <= 100; ++j)
            ans[i][j + 1] += ans[i][j];

    while (q--) {
        cin >> s >> k;
        reverse(s, s + n);
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur = cur * 2 + (s[i] - '0');
        cout << ans[cur][k] << "\n";
    }
}