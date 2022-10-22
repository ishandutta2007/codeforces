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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector <int> t;
    for (int i = 0; i < n; ++i) 
        t.app(b[i]-a[i]);
    for (int i = 0; i < n; ++i)
        t.app(t[i]);
        
    vector <int> pref(t.size()+1);
    for (int i = 0; i < t.size(); ++i)
        pref[i+1] = pref[i]+t[i];

    const int INF = 1e18;
    vector <int> suff(pref.size()+1, INF);
    for (int i = (int)pref.size() - 1; i >= 0; --i)
        suff[i] = min(suff[i+1], pref[i]);

    for (int l = 0; l < n; ++l) {
        int mn = suff[l+1];
        if (b[(l + n - 1) % n] + mn - pref[l] < 0) {
            cout << "No" << endl;
            return;
        }   
    }   

    int sum = 0;
    for (auto e : a)
        sum -= e;
    for (auto e : b)
        sum += e;
    if (sum < 0) {
        cout << "No" << endl;
        return;
    }   

    cout << "Yes" << endl;
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
    while (t--)
        solve();
}