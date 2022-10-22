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
        int k, n;
        cin >> k >> n;
        vector <int> a(n), b(n), c;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            c.app(a[i]);
        }       

        vector <int> suf(n + 1);

        sort(all(c));
        for (int i = n - 1; i >= 0; --i)
            suf[i] = suf[i + 1] + c[i];

        int ans = suf[max(0ll, n - k)];
        for (int i = 0; i < n; ++i) {
            int p = lower_bound(all(c), b[i]) - c.begin();
            if (n - p < k) {
                int so = suf[p];
                if (p == n || a[i] < c[p]) {

                    int del;
                    if (p == n) {
                        del = b[i];
                    }
                    else {
                        del = c[p];
                        if (n - p < k)
                            del = min(del, b[i]);
                    }   

                    so -= del;
                    so += a[i];
                }   
                int nn = so + (k - (n - p)) * b[i];
                ans = max(ans, nn);
            }   
        }   
        cout << ans << endl;
    }   

}