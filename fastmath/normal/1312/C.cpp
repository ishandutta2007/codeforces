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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map <int, int> d;
        while (n--) {
            int x;
            cin >> x;
            vector <int> a;
            while (x) {
                a.app(x % k);
                x /= k;
            }   
            for (int i = 0; i < a.size(); ++i)
                d[i] += a[i];
        }   
        string ans = "YES";
        for (auto e : d)
            if (e.s > 1)
                ans = "NO";
        cout << ans << endl;
    }   
}