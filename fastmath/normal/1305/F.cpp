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
void add(vector <int> &p, int x) {
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            p.app(d);
            while (x % d == 0)
                x /= d;
        }   
    }           
    if (x > 1)
        p.app(x);
}   
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i] & 1;
    mt19937 rnd(2007);
    set <int> mem;
    while (Time < 2) {
        int x = a[rnd() % n];
        vector <int> p;
        add(p, x);
        if (x > 1)
            add(p, x - 1);
        add(p, x + 1);
        for (int w : p) {
            if (mem.find(w) != mem.end())   
                continue;
            mem.insert(w);
            int nn = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] < w)
                    nn += w - a[i];
                else {
                    int r = a[i] % w;
                    nn += min(r, w - r);
                }   
            }   
            ans = min(ans, nn);
        }   
    }   
    cout << ans << '\n';
}