#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Point {
    int x, y;
    Point operator +(Point p) {
        return {x + p.x, y + p.y};
    }   
    Point operator -(Point p) {
        return {x - p.x, y - p.y};
    }   
    int operator *(Point p) {
        return x * p.y - y * p.x;
    }   
    int operator %(Point p) {
        return x * p.x + y * p.y;
    }   
};  
const int N = 301;
Point a[N];
struct Vec {
    int i, j;
    double ang;
};  
bool comp(Vec a, Vec b) {
    return a.ang < b.ang;
}   
const int K = 5;
int dp[N][N][K + 1];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    vector <Vec> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                v.push_back({i, j, atan2(a[j].y - a[i].y, a[j].x - a[i].x)});
            }   
        }   
    }   
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = 1;
    }   
    for (auto e : v) {
        for (int h = K - 1; h >= 0; --h) {
            for (int i = 0; i < n; ++i) {
                dp[i][e.j][h + 1] += dp[i][e.i][h];
            }   
        }
    }   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[i][i][K];
    }   
    cout << ans << '\n';
}