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
const int N = 5e5+7;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    
    int n;
    cin >> n;
    vector <vector <int> > a(n, vector <int> (2));
    auto num = [] (char c) { return c == 'B'; };

    // N - 0
    // B - 1

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            a[i][num(c)]++;            
        }   
    }   
    const int INF = 1e9;
    int mn = INF, mx = -INF;
    for (auto e : a) {
        mn = min(mn, e[0] - e[1]);
        mx = max(mx, e[0] - e[1]);
    }   

    vector <int> mnv(2, INF), mxv(2, -INF);
    for (auto e : a) {
        for (int i = 0; i < 2; ++i) {
            mnv[i] = min(mnv[i], e[i]);
            mxv[i] = max(mxv[i], e[i]);
        }   
    }

    int ans = INF;
    ii best = mp(0, 0);
    for (int x = 0; x < N; ++x) {
        int add = max(x - mnv[0], mxv[0] - x);

        // y - mnv[1]
        // mxv[1] - y
        // (x - y) - mn = (x - mn) - y
        // mx - (x - y) = (mx - x) + y
    
        int t1 = max(-mnv[1], mx - x);
        int t2 = max(mxv[1], x - mn);

        assert( -t1 <= t2 );

        int y = (-t1 + t2) / 2;

        if (x == 0 && y == 0)
            y++;
        else
            y = max(y, 0ll);

        int nn = max({t1 + y, t2 - y, add});
        if (nn < ans) {
            //cout << t1 << ' ' << t2 << endl;
            ans = nn;
            best = mp(x, y);
        }   
    }   

    assert(ans != INF);

    #ifdef HOME
    cout << "dist" << endl;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] <= best.f && a[i][1] <= best.s) {
            cout << max(best.f - a[i][0], best.s - a[i][1]) << endl;
        }   
        else if (a[i][0] >= best.f && a[i][1] >= best.s) {
            cout << max(a[i][0] - best.f, a[i][1] - best.s) << endl;
        }   
        else {
            cout << abs(a[i][0] - best.f) + abs(a[i][1] - best.s) << endl;
        }   
    }   
    cout << "end" << endl;
    #endif

    cout << ans << endl;
    for (int i = 0; i < best.f; ++i)
        cout << 'N';
    for (int i = 0; i < best.s; ++i)
        cout << 'B';
    cout << endl;
}