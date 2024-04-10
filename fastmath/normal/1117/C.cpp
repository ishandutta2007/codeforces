#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e16 + 7;
int n;
int x1, y1_, x2, y2, wx, wy;
const int N = 1e5 + 7;
int dx[N], dy[N];
int getx(int m) {
    return (m / n) * dx[n] + dx[m % n];
}   
int gety(int m) {
    return (m / n) * dy[n] + dy[m % n];
}   
bool check(int m) {
    int tx = getx(m);
    int ty = gety(m);
    return abs(wx - tx) + abs(wy - ty) <= m;
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> x1 >> y1_ >> x2 >> y2;
    wx = x2 - x1;
    wy = y2 - y1_;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            dx[i + 1] = dx[i] - 1;
        }   
        else if (s[i] == 'R') {
            dx[i + 1] = dx[i] + 1;
        }   
        else {
            dx[i + 1] = dx[i];
        }   
    }   

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            dy[i + 1] = dy[i] - 1;
        }   
        else if (s[i] == 'U') {
            dy[i + 1] = dy[i] + 1;
        }   
        else {
            dy[i + 1] = dy[i];
        }   
    }   

    if (!check(INF)) {
        cout << "-1\n";
        exit(0);
    }   
    int l = 0;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }   
    cout << r << '\n';
}