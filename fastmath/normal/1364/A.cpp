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
        int n, x;
        cin >> n >> x;
        int l = n, r = -1;
        vector <int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i]%x) {
                l = min(l, i);
                r = max(r, i);
            }   
        }   
        if (sum%x) {
            cout << n << endl;
        }   
        else if (l == n) {
            cout << -1 << endl;
        }   
        else {
            cout << n - min(l, n - 1 - r) - 1 << endl;
        }   
    }   

}