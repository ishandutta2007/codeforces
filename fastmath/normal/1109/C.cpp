#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N = 1e5 + 7;
bool have[N << 2];
void upd(int v, int tl, int tr, int p, bool x) {
    if (tl == tr) {
        have[v] = x;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p, x);
    else upd(v * 2 + 2, tm + 1, tr, p, x);
    have[v] = have[v * 2 + 1] | have[v * 2 + 2];
}   
int getl(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl || !have[v]) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) >> 1;
    int t = getl(v * 2 + 1, tl, tm, l, r);
    if (t != -1) return t;
    else return getl(v * 2 + 2, tm + 1, tr, l, r);
}   
int getr(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl || !have[v]) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) >> 1;
    int t = getr(v * 2 + 2, tm + 1, tr, l, r);
    if (t != -1) return t;
    else return getr(v * 2 + 1, tl, tm, l, r);
}   
int type[N], a[N], b[N], c[N];
int pos[N];
int ss[N];
struct Letovo {
    int sum, mn;
};  
Letovo tree[N << 2];
Letovo merge(Letovo a, Letovo b) {
    Letovo ans;
    ans.sum = a.sum + b.sum;
    ans.mn = min(a.mn, b.mn + a.sum);
    return ans;
}   
void updt(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        tree[v] = {x, x};
        return;
    }
    int tm = (tl + tr) >> 1;
    if (p <= tm) updt(v * 2 + 1, tl, tm, p, x);
    else updt(v * 2 + 2, tm + 1, tr, p, x);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}
Letovo get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return {0, 0};
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    return merge(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}   
vector <pair <int, int> > v;
void add(int t, int s, int p) {
    upd(0, 0, N, p, 1);
    int l = getr(0, 0, N, 0, p - 1);
    int r = getl(0, 0, N, p + 1, N);
    if (l != -1) {
        updt(0, 0, N, l, (t - v[l].first) * ss[l]);
    }
    if (r != -1) {
        updt(0, 0, N, p, (v[r].first - t) * ss[p]);
    }   
}
void del(int t, int p) {
    upd(0, 0, N, p, 0);
    int l = getr(0, 0, N, 0, p - 1);
    int r = getl(0, 0, N, p + 1, N);
    updt(0, 0, N, p, 0);
    if (l != -1) {
        updt(0, 0, N, l, (v[r].first - v[l].first) * ss[l]);
    }   
}
bool check(int x, int t, int s) {
    return x + t * s <= 0;
}   
double get(int x, int s) {
    return (double)x/abs(s);
}   
int get1(int v, int tl, int tr, int l, int r, int x) {
    if (tl == tr) return tl;
    int tm = (tl + tr) >> 1;
    auto lv = get(0, 0, N, max(l, tl), min(r, tm));
    if (x + lv.mn <= 0) {
        return get1(v * 2 + 1, tl, tm, l, r, x);
    }
    else {
        return get1(v * 2 + 2, tm + 1, tr, l, r, x + lv.sum);
    }   
}   
double get(int l, int r, int x) {
    int l1 = lower_bound(v.begin(), v.end(), make_pair(l, -1ll)) - v.begin();
    int r1 = upper_bound(v.begin(), v.end(), make_pair(r + 1, -1ll)) - v.begin() - 1;
    l1 = getl(0, 0, N, l1, N);
    r1 = getr(0, 0, N, 0, r1);
    if (x == 0) {
        return l;
    }
    else if (r1 < l1 || l1 == -1 || r1 == -1) {
        return -1;
    }
    else if (l1 == r1) {
        if (!check(x, r - v[r1].first, ss[r1])) return -1;
        else return v[r1].first + get(x, ss[r1]);
    }
    else {
        auto tmp = get(0, 0, N, l1, r1 - 1);
        if (tmp.mn + x <= 0) {
            int p = get1(0, 0, N, l1, r1 - 1, x);
            auto t = get(0, 0, N, l1, p - 1);
            x += t.sum;
            return v[p].first + get(x, ss[p]);
        }
        else {
            x += tmp.sum;
            if (!check(x, r - v[r1].first, ss[r1])) return -1;
            else return v[r1].first + get(x, ss[r1]);
        }   
    }   
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin); cout.precision(20);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> type[i];
        if (type[i] == 1) {
            cin >> a[i] >> b[i];
        }
        else if (type[i] == 2) {
            cin >> a[i];
        }
        else {
            cin >> a[i] >> b[i] >> c[i];
        }   
    }
    for (int i = 0; i < q; ++i) {
        if (type[i] == 1) {
            v.push_back({a[i], i});
        }   
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
        pos[v[i].second] = i;
    }   
    for (int i = 0; i < q; ++i) {
        if (type[i] == 1) {
            ss[pos[i]] = b[i];
        }
    }
    map <int, int> d;
    for (int i = 0; i < q; ++i) {
        if (type[i] == 1) {
            d[a[i]] = pos[i];
        }
        else if (type[i] == 2) {
            pos[i] = d[a[i]];
        }   
    }   
    for (int i = 0; i < q; ++i) {
        if (type[i] == 1) {
            add(a[i], b[i], pos[i]);            
        }
        else if (type[i] == 2) {
            del(a[i], pos[i]);
        }
        else {      
            cout << get(a[i], b[i], c[i]) << '\n';
        }   
    }   
}