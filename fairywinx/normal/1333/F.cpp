#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 5e5 + 228;
// const int N = 20;

int p[N];
vector<int> who[N];
int cnt[N];

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            who[j].push_back(i);
            ++cnt[j];
        }
    }

    int sz = 1;
    vector<int> res(n, 1);
    vector<int> pr;
    for (int i = 2; i <= n; ++i) {
        if (cnt[i] == 1) {
            pr.push_back(p[i]);
            ++sz;
        }
    }

    for (int i = 2; i <= n; ++i) {
        for (int p = i; p <= n; p += i) {
            --cnt[p];
            if (cnt[p] == 1) {
                res[sz++] = i;
            }
        }
    }
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, res[i]);
        cout << ans << ' ';
    }
    cout << '\n';
}