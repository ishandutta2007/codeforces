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
    int t;
    cin >> t;

    while (t--) {
        int n, p, m;
        cin >> n >> p >> m;

        int l = p, r = p;

        while (m--) {
            int ql, qr;
            cin >> ql >> qr;
            if (qr < l || r < ql)
                continue;
            l = min(l, ql);
            r = max(r, qr);
        }   
        cout << r - l + 1 << endl;
    }   
}