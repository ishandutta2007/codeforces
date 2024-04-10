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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int b = 40; b >= 0; --b) {
        int sum = (1 << b) - 1;
        vector <int> ans;
        for (int i = 0; i < n; ++i) {
            bool x = (a[i] >> b) & 1;
            if (!x)
                continue;
            ans.app(a[i]);
            sum &= a[i];
        }   
        if (sum == 0 && ans.size()) {
            cout << ans.size() << endl;
            for (int e : ans)
                cout << e << ' ';
            cout << endl;
            exit(0);
        }   
    }   
}