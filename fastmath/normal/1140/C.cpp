#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 7;
int cnt[N << 2], sum[N << 2];

#define t first
#define b second

pair <int, int> a[N];
bool comp(pair <int, int> a, pair <int, int> b) {
    return a.b > b.b;
}   

int per[N];
bool cmp(int i, int j) {
    return a[i].t > a[j].t;
}   
int p[N];

void add(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        cnt[v] = 1;
        sum[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) add(v * 2 + 1, tl, tm, p, x);
    else add(v * 2 + 2, tm + 1, tr, p, x);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    cnt[v] = cnt[v * 2 + 1] + cnt[v * 2 + 2];
}   

int getsum(int v, int tl, int tr, int k) {
    if (tl == tr) return sum[v];
    int tm = (tl + tr) >> 1;
    if (k <= cnt[v * 2 + 1]) return getsum(v * 2 + 1, tl, tm, k);
    else return sum[v * 2 + 1] + getsum(v * 2 + 2, tm + 1, tr, k - cnt[v * 2 + 1]);
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);            
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i].t >> a[i].b;
    sort(a, a + n, comp);

    for (int i = 0; i < n; ++i) per[i] = i;
    sort(per, per + n, cmp);
    for (int i = 0; i < n; ++i) {
        p[per[i]] = i;
    }   

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        add(0, 0, n - 1, p[i], a[i].t);
        if (cnt[0] <= k) {
            ans = max(ans, sum[0] * a[i].b);
        }
        else {
            ans = max(ans, getsum(0, 0, n - 1, k) * a[i].b);
        }
    }   

    cout << ans << '\n';
}