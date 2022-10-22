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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, w;
    cin >> n >> w;

    int cur = 0;
    int l = 0, r = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cur += x;
        l = min(l, cur);
        r = max(r, cur);
    }   

    int l1 = max(0ll, -l);
    int r1 = min(w, w - r);

    cout << max(0ll, r1 - l1 + 1) << endl;
}