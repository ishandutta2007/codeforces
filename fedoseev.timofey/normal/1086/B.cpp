#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

int deg[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int s;
    int n;
    cin >> n >> s;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (deg[i] == 1) ++cnt;
    cout << (ld)s * 2 / cnt << '\n';
}