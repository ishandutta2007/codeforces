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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int t = 0;
    for (int i = 0; i + 1 < n; ++i) {
        t = __gcd(t, abs(a[i + 1] - a[i]));
    }   

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        cout << __gcd(t, a[0] + b[i]) << ' ';
    }   
    cout << endl;
    
}