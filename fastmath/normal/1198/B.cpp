#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
const int N = 2e5 + 7;
int a[N], mx[N];
int pr[N], val[N];
int add[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) { pr[i] = -1; val[i] = a[i]; }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int p, x; cin >> p >> x; --p;
            pr[p] = i; val[p] = x;                
        }   
        else cin >> add[i];
    }   
    for (int i = q - 1; i >= 0; --i) mx[i] = max(mx[i + 1], add[i]);
    for (int i = 0; i < n; ++i) {
        cout << max(mx[pr[i] + 1], val[i]) << ' ';
    }   
    cout << '\n';
}