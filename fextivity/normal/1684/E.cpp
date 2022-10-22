#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5;

template<class T, class F>
struct segment_tree{
    int n, size, log;
    vector<T> data;
    F TT; // monoid operation (always adjacent)
    T T_id; // monoid identity
    // O(n)
    segment_tree(int n, F TT, T T_id): segment_tree(vector<T>(n, T_id), TT, T_id){}
    // O(n)
    segment_tree(int n, T init, F TT, T T_id): segment_tree(vector<T>(n, init), TT, T_id){}
    // O(n)
    segment_tree(const vector<T> &a, F TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id){ // O(n)
        log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
        data = vector<T>(size << 1, T_id);
        copy(a.begin(), a.end(), data.begin() + size);
        for(auto i = size - 1; i >= 1; -- i) refresh(i);
    }
    // O(1)
    void refresh(int i){
        data[i] = TT(data[i << 1], data[i << 1 | 1]);
    }
    // O(log n)
    void set(int p, T x){
        assert(0 <= p && p < n);
        data[p += size] = x;
        for(auto i = 1; i <= log; ++ i) refresh(p >> i);
    }
    // O(log n)
    void update(int p, T x){
        assert(0 <= p && p < n);
        p += size;
        data[p] = TT(data[p], x);
        for(auto i = 1; i <= log; ++ i) refresh(p >> i);
    }
    // O(1)
    T query(int p) const{
        assert(0 <= p && p < n);
        return data[p + size];
    }
    // O(log n)
    T query(int l, int r) const{
        assert(0 <= l && l <= r && r <= n);
        T res_left = T_id, res_right = T_id;
        for(l += size, r += size; l < r; l >>= 1, r >>= 1){
            if(l & 1) res_left = TT(res_left, data[l ++]);
            if(r & 1) res_right = TT(data[-- r], res_right);
        }
        return TT(res_left, res_right);
    }
    // O(1)
    T query_all() const{
        return data[1];
    }
    // pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
    // Returns max r with T
    // O(log n)
    int max_pref(int l, auto pred) const{
        assert(0 <= l && l <= n && pred(T_id));
        if(l == n) return n;
        l += size;
        T sm = T_id;
        do{
            while(~l & 1) l >>= 1;
            if(!pred(TT(sm, data[l]))){
                while(l < size){
                    l = l << 1;
                    if(pred(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
                }
                return l - size;
            }
            sm = TT(sm, data[l ++]);
        }while((l & -l) != l);
        return n;
    }
    // pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
    // Returns min l with T
    // O(log n)
    int min_suff(int r, auto pred) const{
        assert(0 <= r && r <= n && pred(T_id));
        if(r == 0) return 0;
        r += size;
        T sm = T_id;
        do{
            -- r;
            while(r > 1 && r & 1) r >>= 1;
            if(!pred(TT(data[r], sm))){
                while(r < size){
                    r = r << 1 | 1;
                    if(pred(TT(data[r], sm))) sm = TT(data[r --], sm);
                }
                return r + 1 - size;
            }
            sm = TT(data[r], sm);
        }while((r & -r) != r);
        return 0;
    }
    template<class output_stream>
    friend output_stream &operator<<(output_stream &out, const segment_tree<T, F> &seg){
        out << "[";
        for(auto i = 0; i < seg.n; ++ i){
            out << seg.query(i);
            if(i != seg.n - 1) out << ", ";
        }
        return out << ']';
    }
};

int n, k;
int a[N];

int cnt[N];

int posscnt[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    {
        int x = 0, y = n;
        ForE(i, 1, n){
            if (a[i] > n){
                if (x != a[i]){
                    x = a[i]; y++;
                }
                a[i] = y;
            }
        }
    }
    ForE(i, 0, 2 * n){
        cnt[i] = 0;
    }
    ForE(i, 1, n){
        cnt[a[i]]++;
    }
    vpii scnt;
    ForE(i, 0, 2 * n){
        if (cnt[i]){
            scnt.emplace_back(cnt[i], i);
        }
    }
    sort(bend(scnt));
    For(i, 0, isz(scnt)){
        posscnt[scnt[i].se] = i;
    }
    auto add = [&](const pii &lhs, const pii &rhs){
        return make_pair(lhs.fi + rhs.fi, lhs.se + rhs.se);
    };

    segment_tree cac(isz(scnt), add, make_pair(0, 0));
    For(i, 0, isz(scnt)){
        cac.set(i, make_pair(scnt[i].fi, 1));
    }

    int ans = n + 1;

    int diff = isz(scnt), j = 0;
    ForE(i, 0, n){
        if (i > 0 and cnt[i - 1] == 0){
            j++;
        }
        if (i > 0 and cnt[i - 1] != 0){
            diff--;
            cac.set(posscnt[i - 1], make_pair(0, 0));
        }
        if (j > k){
            break;
        }

        int idx = cac.max_pref(0, [&](const pii& a){
            return a.fi <= k;
        });
        int cntrem = cac.query(0, idx).se;
        ans = min(ans, diff - cntrem);
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