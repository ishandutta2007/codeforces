#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

const int MAXN = 3e5 + 7;
const int INF = 1e9 + 7;

int n;
pair <int, int> a[MAXN];

int up = -INF, down = INF, left_ = INF, right_ = -INF;

int get(pair <int, int> a, pair <int, int> b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}   

int get(pair <int, int> a, pair <int, int> b, pair <int, int> c) {
    return get(a, b) + get(b, c) + get(c, a);
}

int get() {
    vector <pair <int, int> > v;
    for (int i = 0; i < n; ++i) {
        if (a[i].x == left_ || a[i].x == right_ || a[i].y == down || a[i].y == up) {
            v.push_back(a[i]);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)v.size(); ++j) {
            for (int k = j; k < (int)v.size(); ++k) {
                ans = max(ans, get(a[i], v[j], v[k]));
            }
        }   
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    for (int i = 0; i < n; ++i) {
        up = max(up, a[i].y);
        down = min(down, a[i].y);
        left_ = min(left_, a[i].x);
        right_ = max(right_, a[i].x);
    }

    cout << get() << ' ';
    for (int i = 4; i <= n; ++i) {
        cout << 2 * (up - down + right_ - left_) << ' ';
    }
    cout << '\n';

    return 0;
}