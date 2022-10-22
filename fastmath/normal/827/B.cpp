#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
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
    int n, k;
    cin >> n >> k;
    vector <ii> ans;
    vector <int> h(k), r(k);
    for (int i = 0; i < k; ++i)
        h[i] = 1;
    for (int i = 0; i < k; ++i) {
        ans.app(mp(1, 2 + i));
        r[i] = 2 + i;
    }
    for (int i = 0; i < n - k - 1; ++i) {
        int j = i % k;
        int v = k + 2 + i;
        ++h[j];
        ans.app(mp(r[j], v));
        r[j] = v;
    }   
    cout << h[0] + h[1] << '\n';
    for (auto e : ans)
        cout << e.f << ' ' << e.s << '\n';
}