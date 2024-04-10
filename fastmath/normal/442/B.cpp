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
    cout.precision(20);
    int n;
    cin >> n;
    vector <double> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            cout << "1.0\n";
            exit(0);
        }   
    }
    sort(all(a));
    double ans = 0;
    for (int l = 0; l < n; ++l) {
        double cur = 1, sum = 0;
        for (int r = l; r < n; ++r) {
            cur = cur * (1 - a[r]);
            sum += a[r] / (1 - a[r]);
            ans = max(ans, sum * cur);
        }   
    }   
    cout << ans << endl;
}