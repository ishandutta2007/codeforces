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
        int n, k;
        cin >> n >> k;
        vector <int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }   

        int ans = n;
        for (int w = 1; w <= 100; ++w) {
            vector <int> p;
            for (int i = 0; i < n; ++i) {
                if (c[i] != w)
                    p.app(i);
            }   
            int nn = 0;
            int ptr = 0;
            while (ptr < p.size()) {
                nn++;
                int s = p[ptr];
                while (ptr < p.size() && p[ptr] - s + 1 <= k)
                    ptr++;
            }   
            ans = min(ans, nn);
        }   
        cout << ans << endl;

    }   

}