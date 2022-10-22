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
        int n;
        cin >> n;
        vector <int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        for (int i = 0; i < n; ++i)
            cin >> c[i];
        int prv = -1;

        vector <int> ans = {a[0]};
        for (int i = 1; i < n; ++i) {
            if (a[i] != ans[0] && a[i] != ans.back())
                ans.app(a[i]);
            else if (b[i] != ans[0] && b[i] != ans.back())
                ans.app(b[i]);
            else
                ans.app(c[i]);
        }   

        for (auto e : ans)
            cout << e << ' ';
        cout << endl;
                        
    }   

}