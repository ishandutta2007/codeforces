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
    int n;
    cin >> n;

    int L = (n + 1)/2;
    int R = n/2;

    vector <int> a(n);
    for (int i = 0; i < L; ++i)
        cin >> a[i];
    int x;
    cin >> x;
    for (int i = L; i < n; ++i)
        a[i] = x;

    vector <int> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];

    vector <int> delt = {0};
    for (int i = 0; i < n; ++i)
        delt.app(delt.back() + x - a[i]);
    vector <int> mn(n + 1);
    for (int i = 0; i < n; ++i)
        mn[i + 1] = min(mn[i], delt[i]);

    for (int k = L; k <= n; ++k) {
        int sum = pref[k];
        if (sum + mn[n - k + 1] > 0) {
            cout << k << endl;
            exit(0);
        }   
    }   
    cout << -1 << endl;
}