#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int INF = 5e18;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, A, R, M;
    cin >> n >> A >> R >> M;

    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    sort(all(a));

    vector <int> pref(n + 1), post(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    for (int i = n - 1; i >= 0; --i)
        post[i] = post[i + 1] + a[i];

    int ans = INF;
    M = min(M, A + R);

    vector <int> c;
    for (int i = 0; i < n; ++i)
        c.app(a[i]);

    const int INF = 1e9 + 7;
    int l = 0, r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;

        int ptr = lower_bound(all(a), m) - a.begin();
        int L = m * ptr - pref[ptr];
        int R = post[ptr] - (n - ptr) * m;

        if (L <= R)
            l = m;
        else
            r = m;
    }   

    c.app(l); c.app(r);
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());

    int ptr = 0;
    for (int x : c) {
        while (ptr < n && a[ptr] < x) {
            ++ptr;
        }   
        int l = ptr * x - pref[ptr];
        int r = post[ptr] - (n - ptr) * x;
        int t = min(l, r);
        ans = min(ans, t * M + (l - t) * A + (r - t) * R);
    }   
    cout << ans << endl;
}