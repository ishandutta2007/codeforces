#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

struct Point {
    int x, y;
    Point(int x_, int y_) {
        x = x_; y = y_;
    }
    Point(){}
};

map <int, set <int> > ms;
map <int, int> l, pr;
map <int, int> num;
Point a[MAXN];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    int curr = 0;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        cin >> a[i].x >> a[i].y;

        int c = a[i].x * a[i].x + a[i].y * a[i].y;

        if (t == 1) {
            for (auto e : ms[c]) {
                int lx = a[e].x + a[i].x;
                int ly = a[e].y + a[i].y;
                int ld = __gcd(lx, ly);
                lx /= ld;
                ly /= ld;
                pr[(lx << 30) + ly]++;
            }
            ms[c].insert(i);
            num[(a[i].x << 30) + a[i].y] = i;
            int lx = a[i].x;
            int ly = a[i].y;
            int ld = __gcd(lx, ly);
            lx /= ld; ly /= ld;
            l[(lx << 30) + ly]++;
            ++curr;
        }
        else if (t == 2) {
            int nn = num[(a[i].x << 30) + a[i].y];
            for (auto e : ms[c]) {
                if (e == nn) continue;
                int lx = a[e].x + a[i].x;
                int ly = a[e].y + a[i].y;
                int ld = __gcd(lx, ly);
                lx /= ld;
                ly /= ld;
                pr[(lx << 30) + ly]--;
            }
            ms[c].erase(nn);
            int lx = a[i].x;
            int ly = a[i].y;
            int ld = __gcd(lx, ly);
            lx /= ld; ly /= ld;
            l[(lx << 30) + ly]--;
            --curr;
        }
        else if (t == 3) {
            int lx = a[i].x;
            int ly = a[i].y;
            int ld = __gcd(lx, ly);
            lx /= ld; ly /= ld;
            cout << curr - l[(lx << 30) + ly] - 2 * pr[(lx << 30) + ly] << '\n';
        }
    }

    return 0;
}