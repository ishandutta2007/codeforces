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
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
        sort(all(a));

        int ans = 0;
        for (int i = 0; i < k; ++i)
            ans += a[n - i - 1];

        vector <int> w(k);
        for (int i = 0; i < k; ++i)
            cin >> w[i];
        sort(all(w));
        reverse(all(w));

        int ptr = n - 1, l = 0;
        for (int i = 0; i < k; ++i) {
            if (w[i] == 1) {
                ans += a[ptr];
                --ptr;
            }       
            else {          
                ans += a[l];
                l += w[i] - 1;
            }   
        }   
        cout << ans << endl;
    }   

}