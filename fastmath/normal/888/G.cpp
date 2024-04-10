#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int L = 30;
int n;
int a[N];
struct Trie {
    Trie *l, *r;
    Trie (Trie *l_, Trie *r_) {
        l = l_; r = r_;
    }   
};  
struct Ans {
    Trie *t;
    long long ans;
};  
int get(Trie *l, Trie *r, int i) {
    if (i == -1) return 0;
    if (l->l && r->l && l->r && r->r) return min(get(l->l, r->l, i - 1), get(l->r, r->r, i - 1));
    else if (l->l && r->l) return get(l->l, r->l, i - 1);
    else if (l->r && r->r) return get(l->r, r->r, i - 1);
    else if (l->l) return get(l->l, r->r, i - 1) + (1 << i);
    else return get(l->r, r->l, i - 1) + (1 << i);
}   
Ans solve(int i, int mn, int mx) {
    if (i == -1) return {new Trie(NULL, NULL), 0};
    int l = lower_bound(a, a + n, mn) - a;
    int r = upper_bound(a, a + n, mx) - a - 1;
    if (a[r] < mn + (1 << i)) {
        auto t = solve(i - 1, mn, mn + (1 << i) - 1);
        t.t = new Trie(t.t, NULL);
        return t;
    }
    if (mn + (1 << i) <= a[l]) {
        auto t = solve(i - 1, mn + (1 << i), mx);
        t.t = new Trie(NULL, t.t);
        return t;
    }
    {
    auto l = solve(i - 1, mn, mn + (1 << i) - 1);
    auto r = solve(i - 1, mn + (1 << i), mx);
    Ans ans;
    ans.ans = l.ans + r.ans + get(l.t, r.t, i - 1) + (1 << i);
    ans.t = new Trie(l.t, r.t);
    return ans;
    }
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    cout << solve(L - 1, 0, (1 << L) - 1).ans << '\n';
}