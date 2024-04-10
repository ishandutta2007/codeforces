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

    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    int n; cin >> n;
    map<int, vector<pair<int, int>>> seg;
    while (n--) {
        int r, a, b; cin >> r >> a >> b;
        seg[r].pb({a, b});
    }

    map<pair<int, int>, bool> checked;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x0, y0}, 0});
    checked[{x0, y0}] = true;
    while (!q.empty()) {
        auto pos = q.front().fi;
        int depth = q.front().se;
        q.pop();
        if (pos.fi == x1 && pos.se == y1) {
            cout << depth;
            return 0;
        }

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                int x = pos.fi + i, y = pos.se + j;
                if (x > 0 && y > 0 && !checked[{x, y}] && !seg[x].empty()) {
                    for (auto& i : seg[x]) {
                        if (y >= i.fi && y <= i.se) {
                            checked[{x, y}] = true;
                            q.push({{x, y}, depth + 1});
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}