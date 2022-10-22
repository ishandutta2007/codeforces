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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector <string> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
            ans += a[i].back() == 'R';
        for (int i = 0; i < m - 1; ++i)
            ans += a[n-1][i] == 'D';
        cout << ans << endl;
    }   

}