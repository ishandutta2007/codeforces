#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

pair<int, int> move(ll x, ll y) {
    cout << x << " " << y << endl;
    string s; cin >> s;
    if (s == "Right") return {0, 1};
    if (s == "Left") return {0, -1};
    if (s == "Down") return {1, 0};
    if (s == "Up") return {1, 0};
    if (s == "Down-Right") return {1, 1};
    if (s == "Down-Left") return {1, -1};
    if (s == "Up-Right") return {-1, 1};
    if (s == "Up-Left") return {-1, -1};
    return {0, 0};
}

ll x = 1, y = 1;

bool moveup() {
    if (x != 1) {
        x = 1;
        auto [dx, dy] = move(x, y);
        if (dx == 0 && dy == 0) return true;
        if (dy > 0) {
            y++;
            auto [dx, dy] = move(x, y);
            if (dx == 0 && dy == 0) return true;
            return false;
        }
    }
    for (int i = 2; i <= 8; i++) {
        x = i;
        auto [dx, dy] = move(x, y);
        if (dx == 0 && dy == 0) return true;
        if (dy > 0) {
            y++;
            auto [dx, dy] = move(x, y);
            if (dx == 0 && dy == 0) return true;
            return false;
        }
        if (dy < 0)
            return false;
    }
    y++;
    auto [dx, dy] = move(x, y);
    if (dx == 0 && dy == 0) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        x = 1, y = 1;
        move(x, y);
        while (y != 7)
            if (moveup()) goto next;

        for (x--; x >= 1; x--) {
            auto [dx, dy] = move(x, y);
            if (dx == 0 && dy == 0) goto next;
        }
        for (x = 2; x <= 8; x++) {
            auto [dx, dy] = move(x, y);
            if (dx == 0 && dy == 0) goto next;
        }
        next:;
    }
}