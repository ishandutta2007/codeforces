#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7;
int a[N], cnt[N], pref[N];
vector <int> c, b;
bool check(int n, int m) {
    int p = ub(all(b), n) - b.begin();
    int sum = pref[p] + ((int)b.size() - p) * n;
    return sum >= n * m;
}   
vector <int> ans[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n_arr;
    cin >> n_arr;
    for (int i = 0; i < n_arr; ++i) {
        cin >> a[i];    
        c.app(a[i]);
    }
    sort(all(c)); c.resize(unique(all(c)) - c.begin());
    for (int i = 0; i < n_arr; ++i) {
        a[i] = lb(all(c), a[i]) - c.begin();
        ++cnt[a[i]];
    }
    for (int i = 0; i < N; ++i)
        if (cnt[i]) 
            b.app(cnt[i]);
    sort(all(b));
    for (int i = 0; i < b.size(); ++i)
        pref[i + 1] = pref[i] + b[i];
    int S = 0, bx, by;
    int y = n_arr;
    for (int x = 1; ; ++x) {
        while (x <= y && !check(x, y))
            --y;
        if (y < x)
            break;
        if (x * y > S) {
            S = x * y;
            bx = x;
            by = y;
        }   
    }
    int n = bx, m = by;
    cout << S << '\n' << bx << ' ' << by << '\n';
    vector <ii> p;  
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            p.app(mp(j, (i + j) % m));
        }   
    }   
    reverse(all(p));
    for (int i = 0; i < n; ++i)
        ans[i].resize(m);
    for (int t = 0; t < N; ++t) {
        if (cnt[t] < n) continue;
        int val = c[t];
        for (int i = 0; i < min(n, cnt[t]) && p.size(); ++i) {
            ans[p.back().f][p.back().s] = val;
            p.pop_back();
        }   
    }   
    for (int t = 0; t < N; ++t) {
        if (!cnt[t] || cnt[t] >= n)
            continue;
        int val = c[t];
        for (int i = 0; i < min(n, cnt[t]) && p.size(); ++i) {
            ans[p.back().f][p.back().s] = val;
            p.pop_back();
        }   
    }   
    if (p.size())
        exit(1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}