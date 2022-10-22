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
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector <bool> have(2);
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        have[b[i]] = 1;
    }

    if (have[0] && have[1]) {
        cout << "Yes" << endl;
        return;
    }   

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            cout << "No" << endl;
            return;
        }   
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