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
const int N = 1e5 + 7, INF = 1e9 + 7;
int n, x[N], v[N];
bool check(double m) {
    double l = 0, r = INF;
    for (int i = 0; i < n; ++i) {
        l = max(l, x[i] - v[i] * m);
        r = min(r, x[i] + v[i] * m);
        if (r < l) return 0;
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> v[i];
    double l = 0, r = INF;
    for (int t = 0; t < 100; ++t) {
        double m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }   
    cout << r << '\n';
}