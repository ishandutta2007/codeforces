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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, d, m;
    cin >> n >> d >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    sort(all(a));

    int r = 0;
    for (auto e : a)
        if (e > m)
            ++r;

    vector <int> pref(n + 1), suff(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    for (int i = n - 1; i >= 0; --i)
        suff[i] = suff[i + 1] + a[i];    

    int l = n - r;
    int ans = 0;
    for (int i = 0; i <= r; ++i) {
        int del = max(0ll, i - 1) * d;
        int nn = suff[n - i];
        if (r - i >= del) {
            nn += pref[l];
            ans = max(ans, nn);
        }   
        else if (l >= del - (r - i)) {
            int wl = l - (del - (r - i));
            nn += pref[l] - pref[l - wl];
            ans = max(ans, nn);
        }   
    }   
    cout << ans << endl;
}