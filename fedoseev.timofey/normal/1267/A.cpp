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
const int N = 2e5 + 7;
int l[N], r[N], t[N];
struct Event {
    int t, type, i;
};  
bool comp(Event a, Event b) {
    return a.t < b.t;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> l[i] >> r[i] >> t[i];
    vector <Event> a;
    for (int i = 0; i < n; ++i) {
        a.app({l[i], 1, i});
        a.app({r[i] - t[i] + 1, 2, i});
    }   
    sort(all(a), comp);
    set <ii> ms;
    for (int i = 0; i < n; ++i) 
        ms.insert(mp(l[i] + t[i], i));
    multiset <int> mn;
    int cur, ans = 0, ptr = 0;
    while ((mn.size() || ms.size())) {
        if (ms.size() && (mn.empty() || ms.begin()->f < cur + *mn.begin())) {
            cur = ms.begin()->f;
            ++ans;
        }   
        else {
            int h = a[ptr].t - cur;
            int len = *mn.begin();
            int add = max(1ll, h / len);
            ans += add;
            cur += add * len;
        }   
        while (ptr < a.size() && a[ptr].t <= cur) {
            int i = a[ptr].i;
            if (a[ptr].type == 1) {
                ms.erase(mp(l[i] + t[i], i));
                mn.insert(t[i]);
            }
            else {
                mn.erase(mn.find(t[i]));
            }   
            ++ptr;
        }   
    }   
    cout << ans << '\n';
}