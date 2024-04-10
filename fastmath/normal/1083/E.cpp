#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;
const int INF = 1e9 + 7;

int n;
struct Kek {
    int x, y, a;
};
Kek a[MAXN];
int dp[MAXN];

vector <pair <int, int> > cht;

int mdiv(int a, int b) {
    int l = -INF;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (m * b < a) {
            l = m;
        }   
        else {
            r = m;
        }   
    }   
    return r;
}   

int per(pair <int, int> a, pair <int, int> b) {
    //x * a.first + a.second = x * b.first + b.second
    //x * (b.first - a.first) = a.second - b.second
    //x = (a.second - b.second) / (b.first - a.first)
    int x = a.second - b.second;
    int y = b.first - a.first;
    return mdiv(x, y);
}   

void add(pair <int, int> l) {
    while (cht.size() >= 2 && per(cht.back(), l) <= per(cht[cht.size() - 2], cht.back())) {
        cht.pop_back();
    }
    cht.push_back(l);
}   

int get(pair <int, int> l, int x) {
    return x * l.first + l.second;
}   

int u = 0;
int get(int x) {
    while (u + 1 < cht.size() && get(cht[u], x) < get(cht[u + 1], x)) {
        ++u;
    }   
    return get(cht[u], x);
}

void calc(int i) {
    dp[i] = get(-a[i].y) - a[i].a + a[i].x * a[i].y;
}   

bool comp(Kek a, Kek b) {
    return a.x < b.x;
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].a;
    }   

    sort(a, a + n, comp);

    add({0, 0});
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        calc(i);
        add({a[i].x, dp[i]});
        ans = max(ans, dp[i]);
    }   

    cout << ans << '\n';
    return 0;
}