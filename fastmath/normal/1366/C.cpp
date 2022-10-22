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

        vector <int> sum(n + m - 1);
        vector <int> t(n + m - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x; cin >> x;
                sum[i + j] += x;
                ++t[i + j];
            }   
        }   

        int k = n + m - 1;
        int ans = 0;
        for (int i = 0; i < k/2; ++i) {
            int tot = t[i] + t[k - 1 - i];
            int s = sum[i] + sum[k - 1 - i];
            ans += min(s, tot - s);             
        }   
        /*
        if (k&1) {
            int num = k/2;
            ans += min(t[num], t[num] - sum[num]);
        }
        */  
        cout << ans << endl;

    }   
}