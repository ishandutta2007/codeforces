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
struct Event {
    int t, i, tp;
};  
bool comp(Event a, Event b) {
    return a.t < b.t;
}   
bool ban[N];
int l[N], r[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <Event> a;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        a.app({l[i], i, 1});
        a.app({r[i] + 1, i, 0});

    }   
    sort(all(a), comp);
    int cur = 0;
    vector <int> ans;
    set <ii> ms;
    int l = 0;
    while (l < a.size()) {
        int rr = l;
        while (rr < a.size() && a[rr].t == a[l].t) {
            auto e = a[rr];
            if (ban[e.i]) {
                ++rr;
                continue;
            }
            if (e.tp) {
                ms.insert(mp(r[e.i], e.i));
                ++cur;
            }   
            else {
                ms.erase(mp(r[e.i], e.i));
                --cur;
            }   
            ++rr;
        }
        while (cur > k) {
            int i = ms.rbegin()->s;
            ms.erase(*ms.rbegin());
            --cur;
            ans.app(i);
            ban[i] = 1;
        }   
        l = rr;
    }       
    cout << ans.size() << '\n';
    for (int e : ans)
        cout << e + 1 << ' ';
    cout << '\n';
}