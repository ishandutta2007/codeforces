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

const int N = 2e5 + 7;
int a[N], pref[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    ++n;
    int r = n;
    map <int, int> d;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        //use pref
        if (d.find(pref[i]) != d.end()) {
            r = min(r, d[pref[i]]);
        }                   
        d[pref[i]] = i;
        ans += r - i;
    }   

    cout << ans - n << endl;
}