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

const int N = 8007;
bool used[N];

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
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 1; i <= n; ++i)
            used[i] = 0;

        for (int l = 0; l < n; ++l) {
            int sum = 0;
            for (int r = l; r < n; ++r) {
                sum += a[r];
                if (r > l && sum <= n)
                    used[sum] = 1;
            }   
        }       

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (used[a[i]]) {
                ++ans;
            }   
        }
        cout << ans << endl;
    }   
}