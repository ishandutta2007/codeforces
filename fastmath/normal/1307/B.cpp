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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        set <int> ms;

        int mx = 0;
        while (n--) {
            int len; cin >> len;
            ms.insert(len);
            mx = max(mx, len);
        }   

        if (ms.find(x) != ms.end()) {
            cout << "1\n";
        }   
        else {
            cout << max(2ll, (x + mx - 1) / mx) << '\n';
        }   

    }   
}