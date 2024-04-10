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

ii get(int a, int b) {
    return mp(min(a, b), max(a, b));
}   

void solve() {
    int n;
    cin >>n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    if (n & 1) {
        if (a[n/2] != b[n/2]) {
            cout << "No" << endl;
            return;
        }   
    }   

    int m = n/2;

    vector <ii> ar, br;

    for (int i = 0; i < m; ++i) {
        ar.app(get(a[i], a[n - 1 - i]));
        br.app(get(b[i], b[n - 1 - i]));
    }   
    
    sort(all(ar)); sort(all(br));
    if (ar == br) {
        cout << "Yes" << endl;
    }   
    else {
        cout << "No" << endl;
    }   
}   
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
        solve();
    }   
}