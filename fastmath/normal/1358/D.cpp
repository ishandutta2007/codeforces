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
int get(int n) {
    return n * (n + 1) / 2;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    reverse(all(a));
    for (int i = 0; i < n; ++i)
        a.app(a[i]);

    vector <int> pref(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) 
        pref[i + 1] = pref[i] + a[i];

    vector <int> t(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) 
        t[i + 1] = t[i] + get(a[i]);

    int ans = 0;
    for (int l = 0; l < n; ++l) {
        /*
        int r = l, w = k, sum = 0;
        while (w) {
            if (w <= a[r]) {
                sum += get(a[r]) - get(a[r] - w);
                break;
            }   
            else {
                sum += get(a[r]);
                w -= a[r];
            }   
            ++r;
        }   
        */

        int p = lower_bound(all(pref), pref[l] + k) - pref.begin() - 1;

        int w = k - (pref[p] - pref[l]);

        int sum = t[p] - t[l] + get(a[p]) - get(a[p] - w);
        ans = max(ans, sum);
    }   
    cout << ans << endl;
}