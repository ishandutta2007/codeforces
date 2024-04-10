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
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, m;
    cin >> n >> m;
    vector <ii> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    vector <ii> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i].x >> b[i].y;
    
    vector <ii> sc;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //if (a[i].x <= b[j].x) {
                sc.app(mp(b[j].x - a[i].x + 1, b[j].y - a[i].y + 1));
            //}
        }   
    }   
    sort(all(sc));

    //check < 0

    int sz = sc.size();
    int ans = max(0ll, sc.back().x);

    int dy = 0;
    for (int i = sz - 1; i >= 0; --i) {
        dy = max(dy, sc[i].y);
        int dx = 0;
        if (i)
            dx = max(0ll, sc[i - 1].x);
        ans = min(ans, dx + dy);
    }                               
    cout << ans << endl;
}