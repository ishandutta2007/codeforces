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
const int N = 3e5 + 7;
int p[N], posx[N], n;
struct Node {
    int sum, mn, res;
    Node () {
        sum = mn = res = 0;
    }
} t[N << 2];  
Node merge(Node l, Node r) {
    Node ans;
    ans.sum = l.sum + r.sum;
    ans.mn = min(l.mn, l.sum + r.mn);
    if (l.res + r.mn >= 0)
        ans.res = l.res + r.sum;
    else
        ans.res = r.sum - r.mn;
    return ans;
}   
void addt(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        t[v].sum += x;
        t[v].mn += x;
        t[v].res = max(t[v].sum, 0ll);
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (i <= tm)
        addt(v * 2 + 1, tl, tm, i, x);
    else
        addt(v * 2 + 2, tm + 1, tr, i, x);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}   
Node get_add(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return Node();
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return merge(get_add(v * 2 + 1, tl, tm, l, r), get_add(v * 2 + 2, tm + 1, tr, l, r));
}   
void addt(int i, int x) {
    addt(0, 1, n, i, x);
}   
Node get_add(int l, int r) {
    return get_add(0, 1, n, l, r);
}   
void add_r(int i) {
    addt(i, -1);    
}
void add_l(int i) {
    addt(i, 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        posx[p[i]] = i;
    }
    int ans = n;
    cout << n << ' ';
    for (int i = 1; i < n; ++i) {
        int b;
        cin >> b;
        add_r(b);
        while (get_add(1, posx[ans] - 1).res + get_add(posx[ans], n).mn < 0) {
            add_l(posx[ans]);
            --ans;
        }   
        cout << ans << ' ';
    }    
    cout << endl;
}