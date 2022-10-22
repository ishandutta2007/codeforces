#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(228);
const int N = 666;
const int M = 500;
const int MX = 999;
set <pair <int, int> > ms;
pair <int, int> a[N + 1];
int get(int x1, int y1, int x2, int y2) {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += x1 <= a[i].first && a[i].first <= x2 && y1 <= a[i].second && a[i].second <= y2;
    }   
    return ans;
}   
bool clear(int x, int y) {
    for (int i = 1; i <= N; ++i) {
        if (a[i].first == x && a[i].second == y) {
            return 0;
        }   
    }   
    return 1;
}   
bool check(int x, int y) {
    return 1 <= x && x <= MX && 1 <= y && y <= MX; 
}
int cnt = 0;
void go(int x, int y) {
    ++cnt;
    #ifdef HOME
    if (cnt % 1 == 0) {
        cout << x << ' ' << y << '\n';
    }   
    while (1) {
        int i = rnd() % N + 1;
        int nx = rnd() % MX + 1;
        int ny = rnd() % MX + 1;
        ms.erase({nx, ny});
        if (ms.find({nx, ny}) == ms.end() && x != nx && y != ny) {
            a[i] = {nx, ny};
            ms.insert({nx, ny});
            break;
        }
        ms.insert({nx, ny});   
    }   
    #else
    cout << x << ' ' << y << '\n';
    fflush(stdout);
    int i;
    cin >> i;
    if (i <= 0) exit(0);
    cin >> a[i].first >> a[i].second;
    #endif
}      
int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}   
int x, y;
void init() {
    x = rnd() % MX + 1;
    y = rnd() % MX + 1;
    set <pair <int, int> > ms;
    for (int i = 1; i <= N; ++i) {
        while (1) {
            int x = rnd() % MX + 1;
            int y = rnd() % MX + 1;
            if (ms.find({x, y}) == ms.end()) {
                ms.insert({x, y});
                a[i] = {x, y};
                break;
            }   
        }   
    }
}   
signed main() {
    #ifdef HOME
    init();
    #else
    cin >> x >> y;
    for (int i = 1; i <= N; ++i) cin >> a[i].first >> a[i].second;
    #endif
    while (x < M) {
        go(x + 1, y);
        ++x;
    }
    while (x > M) {
        go(x - 1, y);
        --x;
    }
    while (y < M) {
        go(x, y + 1);
        ++y;
    }
    while (y > M) {
        go(x, y - 1);
        --y;
    }
    int mn = min(get(1, 1, M - 1, M - 1), get(1, M + 1, M - 1, MX), get(M + 1, 1, MX, M - 1), get(M + 1, M + 1, MX, MX));
    int dx, dy;
    if (get(1, 1, M - 1, M - 1) == mn) {
        dx = -1; dy = -1;
    }
    else if (get(1, M + 1, M - 1, MX) == mn) {
        dx = -1; dy = 1;
    }   
    else if (get(M + 1, 1, MX, M - 1) == mn) {
        dx = 1; dy = -1;
    }   
    else {
        dx = 1; dy = 1;
    }   
    dx *= -1; dy *= -1;
    while (check(x + dx, y + dy)) {
        if (clear(x + dx, y + dy)) {
            go(x + dx, y + dy);
            x += dx; y += dy;
        }
        else {
            go(x + dx, y);
            x += dx;
        }   
    }   
}