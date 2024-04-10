#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e6 + 5, inf = 1e9 + 7;

struct lazy_segment_tree{
    int seg[4 * N], lazy[4 * N];
    
    void down(int id){
        if (!lazy[id]){
            return;
        }
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id];
        seg[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = l - 1;
            lazy[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
        lazy[id] = 0;
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return inf;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
} it;

struct fenwick_tree{
    int bit[N];
    int n;

    void reset(int n){
        this->n = n + 1;
        ForE(i, 0, this->n + 1){
            bit[i] = 0;
        }
    }

    int get(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx){
            ans += bit[idx];
        }
        return ans;
    }

    int get(int l, int r){
        return get(r) - get(l - 1);
    }

    void update(int idx, int delta){
        for (; idx <= n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }
} bit1;


struct query{
    int type, pos, idx; // 1: large -> equal, 2: equal -> small, 3: ask

    query(){

    }

    query(int type, int pos, int idx): type(type), pos(pos), idx(idx){

    }

    friend bool operator< (const query& lhs, const query& rhs){
        if (lhs.pos != rhs.pos){
            return lhs.pos < rhs.pos;
        }
        if (lhs.type != rhs.type){
            return lhs.type < rhs.type;
        }
        return lhs.idx < rhs.idx;
    }
};

int n, m;
int a[N], b[N];

vector <query> vquery;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, m){
        cin >> b[i];
    }

    it.build(1, 1, n + 1);
    sort(b + 1, b + m + 1);
    vquery.clear();
    ForE(i, 1, n){
        vquery.emplace_back(1, a[i], i);
        vquery.emplace_back(2, a[i] + 1, i);
    }
    ForE(i, 1, m){
        vquery.emplace_back(3, b[i], 0);
    }
    sort(bend(vquery));
    ll ans = 0;
    Fora(que, vquery){
        if (que.type == 1){
            it.update(1, 1, n + 1, que.idx + 1, n + 1, -1);
        }
        else if (que.type == 2){
            it.update(1, 1, n + 1, 1, que.idx, 1);
        }
        else{
            ans += it.get(1, 1, n + 1, 1, n + 1);
        }
    }
    {
        int ctrmpp = 0; map <int, int> mpp;
        ForE(i, 1, n){
            mpp[a[i]] = 1;
        }
        Fora(&elem, mpp){
            elem.se = ++ctrmpp;
        }
        ForE(i, 1, n){
            a[i] = mpp[a[i]];
        }
        bit1.reset(ctrmpp);
        ForE(i, 1, n){
            ans += bit1.get(a[i] + 1, ctrmpp);
            bit1.update(a[i], 1);
        }
    }
    cout << ans << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/