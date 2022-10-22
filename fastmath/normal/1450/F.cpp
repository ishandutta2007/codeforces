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

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(n + 1), in(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        in[a[i]]++;
    }
    
    for (int x = 1; x <= n; ++x) {
        if (in[x] > (n + 1) / 2) {
            cout << -1 << endl;
            return;
        }   
    }   

    cnt[a[0]]++;
    cnt[a.back()]++;
    int can = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == a[i + 1]) {
            cnt[a[i]] += 2;
        }   
        else {
            can++;
        }   
    }   

    int sum = 0;
    int mx = 0;
    for (auto e : cnt) {
        sum += e;
        mx = max(mx, e);
    }   

    int ost = sum - mx;
    if (mx > ost + 2) {
        can -= (mx - ost - 2) / 2;
    }   
    assert(can >= 0);
    cout << n - 1 - can << endl;
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