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
const int N = 1e5 + 7;
int a[N], c[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector <ii> ord;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> c[i]; 
        ord.app(mp(c[i], i));
    }
    int ptr = 0;
    sort(all(ord));
    while (m--) {
        int t, d;
        cin >> t >> d;
        --t;
        int ans = 0;
        for (int k = 0; k < d; ) {
            int add;
            if (a[t]) {
                add = min(a[t], d - k);
                a[t] -= add;
                ans += c[t] * add;
            }   
            else {
                while (ptr < n && a[ord[ptr].s] == 0)
                    ++ptr;
                if (ptr == n) {
                    ans = 0;
                    break;
                }
                add = min(a[ord[ptr].s], d - k);
                ans += c[ord[ptr].s] * add;
                a[ord[ptr].s] -= add;
            }   
            k += add;
        }
        cout << ans << endl;                
    }   
}