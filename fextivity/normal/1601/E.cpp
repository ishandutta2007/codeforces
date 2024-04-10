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

const int N = 3e5 + 5, M = 19, inf = 1e9 + 7;

struct lazy_segment_tree{
    ll segsum[4 * N]; int segmx[4 * N]; int lazy[4 * N];
    
    void down(int id, int l, int r){
        if (!lazy[id]){
            return;
        }
        int mid = (l + r) >> 1;
        segsum[id << 1] = (ll)lazy[id] * (mid - l + 1);
        segsum[id << 1 | 1] = (ll)lazy[id] * (r - mid);
        segmx[id << 1] = lazy[id];
        segmx[id << 1 | 1] = lazy[id];
        lazy[id << 1] = lazy[id];
        lazy[id << 1 | 1] = lazy[id];
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            segsum[id] = 0;
            segmx[id] = 0;
            lazy[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        segsum[id] = 0;
        segmx[id] = 0;
        lazy[id] = 0;
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            segsum[id] = (ll)(r - l + 1) * val;
            segmx[id] = val;
            lazy[id] = val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        segsum[id] = segsum[id << 1] + segsum[id << 1 | 1];
        segmx[id] = max(segmx[id << 1], segmx[id << 1 | 1]);
    }
    
    ll getsum(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return segsum[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return getsum(id << 1, l, mid, u, v) + getsum(id << 1 | 1, mid + 1, r, u, v);
    }
    
    int getmx(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return -inf;
        }
        if (u <= l && r <= v){
            return segmx[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return max(getmx(id << 1, l, mid, u, v), getmx(id << 1 | 1, mid + 1, r, u, v));
    }

    int binsearch1(int id, int l, int r, int val){
        if (l == r){
            return l;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        if (segmx[id << 1 | 1] > val){
            return binsearch1(id << 1 | 1, mid + 1, r, val);
        }
        else{
            return binsearch1(id << 1, l, mid, val);
        }
    }
} it;

int n, q, k;
int a[N];
int idk[N], posk[N];
vpii vquery[N];
ll ans[N];

int sptb[M][N];

int query(int l, int r){
    if (l > r){
        return inf;
    }
    int z = __lg(r - l + 1);
    return min(sptb[z][l], sptb[z][r - (1 << z) + 1]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q >> k;
    ForE(i, 1, n){
        cin >> a[i];
        sptb[0][i] = a[i];
    }
    ForE(i, 1, n){
        idk[i] = i % k;
        if (idk[i] == 0){
            idk[i] = k;
        }
        posk[i] = (i + k - 1) / k;
    }
    ForE(i, 1, q){
        int l, r; cin >> l >> r;
        int tr = r / k * k + idk[l];
        while (tr > r){
            tr -= k;
        }
        while (tr + k <= r){
            tr += k;
        }
        vquery[l].emplace_back(tr, i);
    }
    For(j, 1, M){
        ForE(i, 1, n - (1 << j) + 1){
            sptb[j][i] = min(sptb[j - 1][i], sptb[j - 1][i + (1 << (j - 1))]);
        }
    }
    FordE(R, n, n - k + 1){
        int len = posk[R];
        // cout << "R " << R << ' ' << "len " << len << endl;
        it.build(1, 1, len);
        it.update(1, 1, len, len, len, a[R]);
        Fora(&query, vquery[R]){
            ans[query.se] = a[R];
        }
        for (int i = R - k; i >= 1; i -= k){
            int val = query(i, i + k - 1);
            // cout << "i " << i << ' ' << "val " << val << endl;
            if (it.getmx(1, 1, len, 1, len) > val){
                int idx = it.binsearch1(1, 1, len, val);
                // cout << "idx " << idx << endl;
                it.update(1, 1, len, posk[i] + 1, idx, val);
            }
            it.update(1, 1, len, posk[i], posk[i], a[i]);
            // cout << "it ";
            // ForE(i, 1, len){
            //     cout << it.getsum(1, 1, len, i, i) << ' ';
            // } cout << endl;
            Fora(&query, vquery[i]){
                ans[query.se] = it.getsum(1, 1, len, posk[i], posk[query.fi]);
            }
        }
    }
    ForE(i, 1, q){
        cout << ans[i] << endl;
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