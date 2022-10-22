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
int ans[N];
ii seg[N]; 
struct Seg {
    int l, r, i;
};   
bool comp(Seg a, Seg b) {
    return a.r < b.r;
}
Seg a[N];
vector <int> open[N]; 
int who[N];

int mn[N << 2];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        mn[v] = a[who[tl]].l;
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); 
    build(v * 2 + 2, tm + 1, tr);
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
}   
int find(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl || mn[v] > x)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    int t = find(v * 2 + 1, tl, tm, l, r, x);
    if (t != -1)
        return t;
    else
        return find(v * 2 + 2, tm + 1, tr, l, r, x);
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
        open[a[i].l].app(i);
    }   
    set <ii> ms;
    for (int i = 1; i <= n; ++i) {
        for (int j : open[i]) {
            ms.insert(mp(a[j].r, j));
        }   
        who[i] = ms.begin()->s;
        ms.erase(ms.begin());
        ans[who[i]] = i;
    }
    build(0, 1, n);
    for (int i = 1; i <= n; ++i) {
        int l = who[i];
        int j = find(0, 1, n, i + 1, a[l].r, i);
        if (j != -1) {
            int r = who[j];
            cout << "NO" << endl;
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << ' ';
            }   
            cout << endl;
            swap(ans[l], ans[r]);
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << ' ';
            }   
            cout << endl;
            exit(0);
        }   
    }   
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}