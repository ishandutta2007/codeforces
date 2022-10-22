#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 401;
const int M = 3e5 + 7;
const int INF = 1e18 + 7;
int n, m;
struct Kek {
    int s, f, c, r;
};  
int a[N];
mt19937 rnd(228);
Kek d[M];
int per[M];
bool check(int i, int v) {
    v /= d[i].c;
    int l = d[i].s, r = d[i].f;
    for (int i = l; i < r; ++i) {
        if (a[i + 1] - a[i] > v) return 0;
    }   
    int add = 0;
    int u = l;
    while (1) {
        int t = u;
        int ost = v;
        while (t < r && a[t + 1] - a[t] <= ost) {
            ost -= a[t + 1] - a[t];
            ++t;
        }   
        if (t == r) {
            break;
        }   
        else {
            ++add;
            u = t;
        }
    }   
    return add <= d[i].r;
}
int get(int i) {
    int l = 0;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(i, m)) r = m;
        else l = m;
    }   
    return r;
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        cin >> d[i].s >> d[i].f >> d[i].c >> d[i].r;
        --d[i].s; --d[i].f;
    }   
    for (int i = 0; i < m; ++i) per[i] = i;
    shuffle(per, per + m, rnd);
    int ans = 0;
    for (int ii = 0; ii < m; ++ii) {
        int i = per[ii];
        if (!check(i, ans)) {
            ans = max(ans, get(i));
        }
    }   
    cout << ans << '\n';
    return 0;
}