#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int a[MAXN];
vector <int> p[MAXN];

int ans[MAXN];

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[a[i]].push_back(i);
    }

    int u = 1;
    for (int i = 0; i < n; ++i) {
        int sz = n - i;
        if (p[i].size() % sz) {
            cout << "Impossible\n";
            exit(0);
        }
        else {
            int k = p[i].size() / sz;
            for (int j = 0; j < k; ++j) {
                for (int t = 0; t < sz; ++t) {
                    ans[p[i][j * sz + t]] = u;
                }
                ++u;
            }
        }
    }

    cout << "Possible\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}