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
#define debug(x) std::cout << #x << ": " << x << '\n';

int n, m, q;
vector <ii> d;

const int INF = 1e18;

bool check(int k) {
    vector <ii> a, b;
    for (int i = 0; i < k; ++i) {
        if (d[i].f & 1) {
            a.app(mp(d[i].f/2, d[i].s/2));
        }   
        else {
            b.app(mp(d[i].f/2, d[i].s/2));
        }   
    }   

    sort(all(a));
    sort(all(b));

    int mn = INF;
    int ptr = 0;
    for (auto e : a) {
        while (ptr < b.size() && b[ptr].f <= e.f) {
            mn = min(mn, b[ptr].s);
            ++ptr;
        }   
        if (mn <= e.s)
            return 0;
    }   
    return 1;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        d.app(mp(x, y));
    }   

    int l = 0, r = d.size() + 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m))
            l = m;
        else
            r = m;
    }   

    for (int i = 0; i < l; ++i)
        cout << "YES" << endl;
    for (int i = l; i < q; ++i)
        cout << "NO" << endl;
}