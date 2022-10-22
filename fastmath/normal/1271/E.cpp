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
const int INF = 2e18;
int n, k;
vector <ii> a[2];
int get(int x) {
    if (x > n)
        return 0;
    auto t = lower_bound(all(a[x & 1]), mp(x + 1, 0ll));
    if (t == a[x & 1].begin()) return -INF;
    --t;
    return t->s;
}   
bool check(int x) {
    return get(x) >= k;
}   
int get1(int x) {
    if (x > n)
        return 0;
    if (x & 1)
        return get(x * 2) + 1;
    else
        return get(x * 2) + get(x + 1) + 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    int l = n + 1;
    a[0].app(mp(n + 1, 0));
    a[1].app(mp(n + 1, 0));
    while (l > 1) {
        int l1 = (l + 1) / 2;

        int t = l - 1;
        if (t % 2 == 0)
            --t;
        while (t >= l1) {
            for (int i = 60; i; --i) {
                int to = t - (1ll << i);
                if (to > 0 && get1(to) == get1(t))
                    t = to;
            }
            if (t < l1)
                break;
            a[1].app(mp(t, get1(t)));
            sort(all(a[1]));
            t -= 2;
        }

        t = l - 1;
        if (t & 1)
            --t;
        while (t >= l1) {
            for (int i = 60; i; --i) {
                int to = t - (1ll << i);
                if (to > 0 && get1(to) == get1(t))
                    t = to;
            }   
            if (t < l1)
                break;
            a[0].app(mp(t, get1(t)));
            sort(all(a[0]));
            t -= 2;
        }

        l = l1;
    }   
    int a = 1;
    for (int i = 60; i; --i) 
        if (check(a + (1ll << i)))
            a += 1ll << i;
    int b = 0;
    for (int i = 60; i; --i) 
        if (check(b + (1ll << i)))
            b += 1ll << i;
    cout << max(a, b) << '\n';
}