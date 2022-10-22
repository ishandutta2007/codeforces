#include<bits/stdc++.h>
using namespace std;
#define Point pair <int, int>
#define x first
#define y second
const int N = 1e5 + 7;
const int K = 301;
const int INF = 1e9 + 7;
int n, k;
Point a[N];
struct Event {
    int t, i;
    bool add;
};  
bool comp(Event a, Event b) {
    return a.t < b.t;
}
int cnt = 0;
int cur[N];
long long ans[N];
int bal[N * K];
vector <int> ay, y;
void upd(Event e) {
    if (e.add) {
        ++cnt;
        auto p = lower_bound(y.begin(), y.end(), a[e.i].y - k + 1) - y.begin();
        for (int i = p; i < p + k; ++i) {
            --cur[bal[i]];
            ++bal[i];    
            ++cur[bal[i]];
        }   
    }
    else {
        --cnt;
        auto p = lower_bound(y.begin(), y.end(), a[e.i].y - k + 1) - y.begin();
        for (int i = p; i < p + k; ++i) {
            --cur[bal[i]];
            --bal[i];    
            ++cur[bal[i]];
        }   
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    for (int i = 0; i < n; ++i) ay.push_back(a[i].y);
    sort(ay.begin(), ay.end());
    y.reserve(N * K);
    int pr = -INF;
    for (int ny : ay) {
        for (int i = max(pr + 1, ny - k + 1); i <= ny; ++i) {
            y.push_back(i);
        }   
        pr = ny;
    }   
    vector <Event> ev;
    for (int i = 0; i < n; ++i) {
        ev.push_back({a[i].x - k + 1, i, 1});
        ev.push_back({a[i].x + 1, i, 0});
    }   
    sort(ev.begin(), ev.end(), comp);
    for (int i = 0; i + 1 < (int)ev.size(); ++i) {
        upd(ev[i]);
        if ((ev[i + 1].t - ev[i].t)) {
            for (int c = 1; c <= cnt; ++c) {
                ans[c] += cur[c] * (ev[i + 1].t - ev[i].t);
            }   
        }
    }   
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}