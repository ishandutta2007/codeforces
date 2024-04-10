#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int MEM = 1e5 + 7;

const int N = 4e5 + 7;

set <int> who[2][N];
int get(int dx, int dy) {
    if ((dx == 1 && dy == 1) || (dx == -1 && dy == -1)) {
        return 1;
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> x(k), y(k);

    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
        who[0][x[i] + y[i]].insert(i);
        who[1][x[i] - y[i] + MEM].insert(i);
    }

    vector <int> ans(k, -1);

    int cx = 0, cy = 0;
    int dx = 1, dy = 1;
    map <pair <int, int>, int> used;

    used[make_pair(n, m)] = 1;
    used[make_pair(0, m)] = 1;
    used[make_pair(n, 0)] = 1;
    int timer = 0;
    while (true) {
        //cout << cx << ' ' << cy << ' ' << dx << ' ' << dy << endl;
        if (used[make_pair(cx, cy)]) break;
        used[make_pair(cx, cy)] = 1;
        int w = get(dx, dy);
        int s;
        int os;
        s = cx + cy;
        os = cx - cy + MEM;
        if (w == 1) swap(s, os);

        for (auto id : who[w][s]) {
            if (ans[id] == -1) ans[id] = abs(x[id] - cx) + timer;
            who[w ^ 1][os].erase(id);
        }
        int mn = 1e9;
        int wh = -1;
        if (n - cx / dx > 0 && mn > n - cx / dx) {
            wh = 0;
            mn = n - cx / dx;
        }
        if (-cx / dx > 0 && mn > -cx / dx) {
            wh = 1;
            mn = -cx / dx;
        }
        if (m - cy / dy > 0 && mn > m - cy / dy) {
            mn = m - cy / dy;
            wh = 2;
        }
        if (-cy / dy > 0 && mn > -cy / dy) {
            mn = -cy / dy;
            wh = 3;
        }
        timer += mn;
        cx += dx * mn;
        cy += dy * mn;

        if (wh <= 1) {
            dx *= -1;
        }
        else {
            dy *= -1;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << '\n';
    }
}