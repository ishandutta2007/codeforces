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

        int l1, r1;
        cin >> l1 >> r1;

        int l2, r2;
        cin >> l2 >> r2;

        int have = min(r1, r2) - max(l1, l2);
        have = max(have, 0ll);

        if (have * n >= k) {
            cout << 0 << endl;
            continue;
        }   

        k -= have * n;

        int wait = 0;
        if (min(r1, r2) - max(l1, l2) < 0)
            wait = abs(min(r1, r2) - max(l1, l2));

        int add = max(r1, r2) - min(l1, l2) - have;

        int ans = 5e18;
        for (int i = 1; i <= n; ++i) {
            int t = wait * i;

            if (add * i >= k) {
                t += k;
            }   
            else {
                t += add * i;
                int want = k - add * i;
                t += 2 * want;
            }   

            ans = min(ans, t);
        }   
        cout << ans << endl;
    }   
}