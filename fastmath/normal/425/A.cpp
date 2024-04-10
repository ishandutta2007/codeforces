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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    const int INF = 1e9 + 7;
    int ans = -INF;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {

            vector <int> in;
            for (int i = l; i <= r; ++i)
                in.app(a[i]);
            vector <int> out;
            for (int i = 0; i < l; ++i)
                out.app(a[i]);
            for (int i = r + 1; i < n; ++i)
                out.app(a[i]);

            int cur = 0;
            for (int e : in)
                cur += e;

            sort(all(in));
            sort(all(out)); reverse(all(out));
            for (int i = 0; i <= k && i <= min(in.size(), out.size()); ++i) {
                int add = 0;
                for (int j = 0; j < i; ++j)
                    add += out[j] - in[j];
                ans = max(ans, cur + add);
            }   
            
        }   
    }   
    cout << ans << endl;
}