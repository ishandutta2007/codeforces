#include <bits/stdc++.h>

using namespace std;

#define int long long

int getw(int a, int b, int x, int y) {
    return a * b / 2 + ((a * b) % 2 && (x + y) % 2 == 0);
}

int getb(int a, int b, int x, int y) {
    return a * b / 2 + ((a * b) % 2 && (x + y) % 2 == 1);
}      

void solve() {
    int n, m;
    cin >> n >> m;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int inter = 0;
    int lx = max(x1, x3);
    int rx = min(x2, x4);
    int ly = max(y1, y3);
    int ry = min(y2, y4);
    if (lx <= rx && ly <= ry) {
        inter = (rx - lx + 1) * (ry - ly + 1);
    }   

    int ans1 = 0;
    ans1 += getw(n, m, 1, 1);
    ans1 -= getw(x2 - x1 + 1, y2 - y1 + 1, x1, y1) + getw(x4 - x3 + 1, y4 - y3 + 1, x3, y3);
    if (inter) {
        ans1 += getw(rx - lx + 1, ry - ly + 1, lx, ly);
    }
    ans1 += (x2 - x1 + 1) * (y2 - y1 + 1);
    ans1 -= inter;

    int ans2 = 0;
    ans2 += getb(n, m, 1, 1);
    ans2 -= getb(x2 - x1 + 1, y2 - y1 + 1, x1, y1) + getb(x4 - x3 + 1, y4 - y3 + 1, x3, y3);
    if (inter) {
        ans2 += getb(rx - lx + 1, ry - ly + 1, lx, ly);
    }
    ans2 += (x4 - x3 + 1) * (y4 - y3 + 1);

    cout << ans1 << ' ' << ans2 << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        solve();
    }   

    return 0;
}