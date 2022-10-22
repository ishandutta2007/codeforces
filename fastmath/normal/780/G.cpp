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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7, MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {    
    if (n < MOD) return n;
    else return n - MOD;
}   
int h, w, n;
int row[N], l[N], r[N], s[N];
struct Event {
    int x, type, i;
};  
bool comp(Event a, Event b) {
    return (a.x < b.x) || (a.x == b.x && a.type < b.type);
}   
int dp[N];

set <ii> ms[N << 2];
void add(int v, int tl, int tr, int l, int r, int i) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        ms[v].insert(mp(row[i], i));
        return;
    }   
    int m = (tl + tr) >> 1;
    add(v * 2 + 1, tl, m, l, r, i);
    add(v * 2 + 2, m + 1, tr, l, r, i);
}   
void del(int v, int tl, int tr, int l, int r, int i) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        ms[v].erase(mp(row[i], i));
        return;
    }   
    int m = (tl + tr) >> 1;
    del(v * 2 + 1, tl, m, l, r, i);
    del(v * 2 + 2, m + 1, tr, l, r, i);
}   
ii get(int v, int tl, int tr, int i) {
    ii ans = {-1, -1};
    if (ms[v].size()) ans = *ms[v].rbegin();
    if (tl == tr) return ans;
    int m = (tl + tr) >> 1;
    if (i <= m) return max(ans, get(v * 2 + 1, tl, m, i));
    else return max(ans, get(v * 2 + 2, m + 1, tr, i));
}   

void add(int i) {
    add(0, 0, N, l[i], r[i], i);
}
void del(int i) {
    del(0, 0, N, l[i], r[i], i);
}   
int get(int p) {
    auto t = get(0, 0, N, p);
    if (t.s == -1) return 1;
    else return dp[t.s];
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> h >> w >> n;
    vector <Event> e;
    for (int i = 0; i < n; ++i) {
        cin >> row[i] >> l[i] >> r[i] >> s[i];
        e.app({row[i], 0, i});
        if (row[i] + s[i] <= h) e.app({row[i] + s[i], 1, i});
    }            
    sort(all(e), comp);
    for (auto t : e) {
        if (t.type) {
            del(t.i);
        }
        else {
            if (l[t.i] == 1) 
                dp[t.i] = mod(get(r[t.i] + 1) << 1);
            else if (r[t.i] == w)
                dp[t.i] = mod(get(l[t.i] - 1) << 1);
            else 
                dp[t.i] = mod(get(l[t.i] - 1) + get(r[t.i] + 1));
            add(t.i);
        }   
    }   
    int ans = 0;
    for (int i = 1; i <= w; ++i) 
        ans = mod(ans + get(i));
    cout << ans << '\n';
}