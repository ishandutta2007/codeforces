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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2007;
ii a[N];
bool c[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].f >> a[i].s;                       
    }   
    while (1) {
        c[0] = c[1] = 0;
        for (int i = 0; i < n; ++i) 
            c[(a[i].f + a[i].s) & 1] = 1;
        if (c[0] && c[1]) {
            vector <int> ans;
            for (int i = 0; i < n; ++i)
                if ((a[i].f + a[i].s) & 1)
                    ans.app(i);
            cout << ans.size() << '\n';
            for (int e : ans)
                cout << e + 1 << ' ';
            cout << '\n';
            exit(0);
        }
        for (int i = 0; i < n; ++i) {
            int x = a[i].f + a[i].s;
            int y = a[i].f - a[i].s;
            x += x & 1;
            y += y & 1;
            a[i].f = x / 2;
            a[i].s = y / 2;
        }   
    }   
}