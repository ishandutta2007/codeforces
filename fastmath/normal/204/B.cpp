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
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e5 + 7;
map <int, int> a, b;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> c;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        c.app(x); c.app(y);            
        ++a[x];
        if (x != y)
            ++b[y];
    }   
    int ans = N;
    int w = (n + 1) / 2;
    for (int e : c) {
        if (a[e] >= w)
            ans = 0;
        else if (a[e] + b[e] >= w)
            ans = min(ans, w - a[e]);
    }   
    if (ans == N)
        cout << -1 << endl;
    else
        cout << ans << endl;
}