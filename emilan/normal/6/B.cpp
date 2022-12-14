#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
    freopen("io\\err.txt", "w", stderr);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007



int main() {
    ioThings();

    int n, m; cin >> n >> m;
    char c; cin >> c;
    vector<string> r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i];
    
    set<char> colors;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (r[i][j] == c) {
                if (i - 1 != -1)
                    colors.insert(r[i - 1][j]);
                if (i + 1 != n)
                    colors.insert(r[i + 1][j]);
                if (j - 1 != -1)
                    colors.insert(r[i][j - 1]);
                if (j + 1 != m)
                    colors.insert(r[i][j + 1]);
            }
        }
    }
    
    cout << sz(colors) - colors.count('.') - colors.count(c);

    return 0;
}