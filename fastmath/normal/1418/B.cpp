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
        vector <int> a(n), l(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }   
        vector <int> v;
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            if (!l[i]) {
                v.app(a[i]);
            }   
        }   
        sort(all(v));
        reverse(all(v));
        int ptr = 0;
        int cur = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (!l[i]) {
                a[i] = v[ptr++];
            }   
            cur += a[i];
            if (cur < 0)
                mx = max(mx, i + 1);
        }   
        //cout << mx << endl;
        for (auto e : a)
            cout << e << ' ';
        cout << endl;
    }   
}