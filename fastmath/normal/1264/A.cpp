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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7;
void solve() {
    int n; cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    int cnt = 0;
    vector <int> a;
    for (int i = 0; i < n; ++i) 
        if (i && p[i] != p[i - 1]) {
            a.app(cnt);
            cnt = 1;
        }
        else ++cnt;
    a.app(cnt);           
    int ptr = 1, s = 0;
    while (s <= a[0]) {
        if (ptr == a.size()) {
            cout << "0 0 0\n";
            return;
        }   
        s += a[ptr];
        ptr++;
    }   
    int b = 0;
    while (b <= a[0]) {
        if (ptr == a.size()) {
            cout << "0 0 0\n";
            return;
        }   
        b += a[ptr];
        ptr++;
    }   
    if ((a[0] + s + b) * 2 > n) {
        cout << "0 0 0\n";
        return;
    }    
    while (ptr < a.size() && (a[0] + s + b + a[ptr]) * 2 <= n) {
        b += a[ptr];
        ++ptr;
    }   
    cout << a[0] << ' ' << s << ' ' << b << '\n';        
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) solve();
}