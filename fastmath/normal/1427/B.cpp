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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int cur = 0;
        int L = 0;
        vector <int> gap;
        int prv = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                cur++;
                if (prv != -1) {
                    gap.app(i - prv - 1);
                }   
                prv = i;
            }   
            else {
                L++;
            }   
        }   
        
        if (L == n) {
            if (k == 0) {
                cout << 0 << endl;
            }   
            else {
                cout << 1 + (k - 1) * 2 << endl;
            }   
        }
        else if (L <= k) {
            cout << 1 + (n - 1) * 2 << endl;
        }   
        else {
            int ans = cur;
            ans += k * 2;
            sort(all(gap));
            for (auto e : gap) {
                if (e > k)
                    break;
                k -= e;
                ans++;
            }   
            cout << ans << endl;
        }   
    }   
}