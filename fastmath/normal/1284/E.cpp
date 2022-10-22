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
#define double long double
void add(int &cnt, int &ans) {
    ans -= cnt * (cnt - 1) * (cnt - 2) / 6;            
    ++cnt;
}   
signed main() {
    #ifdef HOME     
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <ii> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].f >> a[i].s;
    int ans = 5;
    for (int i = n; i > n - 5; --i) 
        ans *= i;
    ans /= 120;
    swap(a[0], a[1]);
    const double PI = acos(-1);
    for (int i = 0; i < n; ++i) {
        vector <pair <double, bool> > ev;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double l = atan2(a[j].s - a[i].s, a[j].f - a[i].f);
                double r = atan2(-a[j].s + a[i].s, -a[j].f + a[i].f);
                if (r < l)
                    ++cnt;
                ev.app(mp(l, 1));
                ev.app(mp(r, 0));
            }   
        }   
        sort(all(ev));
        for (auto e : ev) {
            if (e.s) 
                add(cnt, ans);
            else 
                --cnt;
        }
    }   
    cout << ans << '\n';
}