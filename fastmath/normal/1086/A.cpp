#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

pair <int, int> a[3];

int get(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans += abs(x - a[i].first) + abs(y - a[i].second);
    }   
    return ans + 1;
}   

const int INF = 1e9 + 7;

vector <pair <int, int> > p;

void get1(int x, int y) {
    p.push_back({x, y});
    for (int i = 0; i < 3; ++i) {

        int dx, dy;
        if (x < a[i].first) {
            dx = 1;
        }   
        else {
            dx = -1;
        }   

        if (y < a[i].second) {
            dy = 1;
        }   
        else {
            dy = -1;
        }   

        int tx = x, ty = y;
        for (int t = 0; t < abs(x - a[i].first); ++t) {
            tx += dx;
            p.push_back({tx, ty});
        }   

        for (int t = 0; t < abs(y - a[i].second); ++t) {
            ty += dy;
            p.push_back({tx, ty});
        }   
    }   
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #else   
        
    #endif

    for (int i = 0; i < 3; ++i) {
        cin >> a[i].first >> a[i].second;
    }   

    int ans = INF, x = -1, y = -1;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            if (get(i, j) < ans) {
                ans = get(i, j);
                x = i;
                y = j;
            }
        }   
    }   

    cout << ans << '\n';
    get1(x, y);
    for (auto e : p) {
        cout << e.first << ' ' << e.second << '\n';
    }   

    return 0;
}