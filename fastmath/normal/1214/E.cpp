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
int d[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <ii> a;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];    
        a.app(mp(d[i], i));
    }
    sort(all(a));
    reverse(all(a));
    vector <int> p;
    for (int i = 0; i < n; ++i)
        p.app(2 * a[i].s - 1);
    for (int i = 0; i + 1 < n; ++i)
        cout << p[i] << ' ' << p[i + 1] << '\n';
    for (int i = 0; i < n; ++i) {
        int u = p[i + a[i].f - 1];
        cout << u << ' ' << p[i] + 1 << '\n';
        if (u == p.back())
            p.app(p[i] + 1);
    }   
}