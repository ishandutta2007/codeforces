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

    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> black(m);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '#')
                black[j]++;
    }

    // pos, color, occurrence -> min paint
    vector<vector<vector<int>>>
        c(m, vector<vector<int>>(2, vector<int>(y + 1, 1e6)));
    c[0][0][1] = black[0]; // white
    c[0][1][1] = n - black[0]; // black
    for (int i = 1; i < m; i++) {
        c[i][0][1] = 
            *min_element(c[i - 1][1].begin() + x, c[i - 1][1].end())
            + black[i];
        for (int j = 1; j < y; j++)
            c[i][0][j + 1] = c[i - 1][0][j] + black[i];
        c[i][1][1] = 
            *min_element(c[i - 1][0].begin() + x, c[i - 1][0].end())
            + n - black[i];
        for (int j = 1; j < y; j++)
            c[i][1][j + 1] = c[i - 1][1][j] + n - black[i];
    }

    cout << min(*min_element(c.back()[0].begin() + x, c.back()[0].end()),
                *min_element(c.back()[1].begin() + x, c.back()[1].end()));

    return 0;
}