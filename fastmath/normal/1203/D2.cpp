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
int pref[N], post[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i];
        if (pref[i] < m && s[i] == t[pref[i]])
            ++pref[i + 1];
    }   
    for (int i = n - 1; i >= 0; --i) {
        post[i] = post[i + 1];
        if (post[i] < m && s[i] == t[t.size() - 1 - post[i]])
            ++post[i];
    }   

    int ans = 0, r = -1;
    for (int l = 0; l < n; ++l) {
        r = max(r, l - 1);
        while (r + 1 < n && pref[l] + post[r + 2] >= m)
            ++r;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
}