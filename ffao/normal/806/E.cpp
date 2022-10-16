#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    std::vector<T> value;
 
    U noop;
    std::vector<bool> dirty;
    std::vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U());
    void set_leaves(std::vector<T> &leaves);
    void apply(int i, U &update);
    void rebuild(int i);
    void propagate(int i);
    void upd(int i, int j, U update);
    T query(int i, int j);
};

template<typename T, typename U>
seg_tree_lazy<T, U>::seg_tree_lazy(int _S, T _zero, U _noop) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }

template<typename T, typename U>
void seg_tree_lazy<T, U>::set_leaves(vector<T> &leaves) {
    copy(leaves.begin(), leaves.end(), value.begin() + S);

    for (int i = S - 1; i > 0; i--)
        value[i] = value[2 * i] + value[2 * i + 1];
}

template<typename T, typename U>
void seg_tree_lazy<T, U>::apply(int i, U &update) {
    value[i] = update(value[i]);
    if(i < S) {
        prop[i] = prop[i] + update;
        dirty[i] = true;
    }
}

template<typename T, typename U>
void seg_tree_lazy<T, U>::rebuild(int i) {
    for (int l = i/2; l; l /= 2) {
        T combined = value[2*l] + value[2*l+1];
        value[l] = prop[l](combined);
    }
}

template<typename T, typename U>
void seg_tree_lazy<T, U>::propagate(int i) {
    for (int h = H; h > 0; h--) {
        int l = i >> h;

        if (dirty[l]) {
            apply(2*l, prop[l]);
            apply(2*l+1, prop[l]);

            prop[l] = noop;
            dirty[l] = false;
        }
    }
}

template<typename T, typename U>
void seg_tree_lazy<T, U>::upd(int i, int j, U update) {
    i += S, j += S;
    propagate(i), propagate(j);

    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
        if((l&1) == 1) apply(l++, update);
        if((r&1) == 0) apply(r--, update);
    }

    rebuild(i), rebuild(j);
}

template<typename T, typename U>
T seg_tree_lazy<T, U>::query(int i, int j){
    i += S, j += S;
    propagate(i), propagate(j);

    T res_left = zero, res_right = zero;
    for(; i <= j; i /= 2, j /= 2){
        if((i&1) == 1) res_left = res_left + value[i++];
        if((j&1) == 0) res_right = value[j--] + res_right;
    }
    return res_left + res_right;
}
#endif

struct node {
    int sm;

    node(int sm = 1000000000) : sm(sm) {}

    node operator+(node ot) {
        ot.sm = min(sm, ot.sm);
        return ot;
    }
};

struct update {
    int delta, s;

    update(int delta=0, int s=-0x3f3f3f3f) : delta(delta), s(s) {}

    update operator+(update ot) {
        ot.delta += delta;
        if (ot.s == -0x3f3f3f3f) ot.s = s;
        return ot;
    }

    node operator()(node n) {
        n.sm += delta;
        if (s != -0x3f3f3f3f) n.sm = s;
        return n;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vi a(n);
    vi sorted_index(n);
    seg_tree_lazy<node, update> seg(n);

    vi tree(n+10);
    auto get = [&](int x) { 
        int s = 0; 
        for (; x > 0; x -= x&-x) s += tree[x]; 
        return s;
    };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pii> sorted(n);
    for (int i = 0; i < n; i++) {
        sorted[i] = {a[i], i};
    }
    sort(all(sorted));
    for (int i = 0; i < n; i++) {
        sorted_index[sorted[i].second] = i;
    }

    set<int> indices;
    int freefall = n;

    for (int i = 0; i < n; i++) {
        indices.insert(sorted_index[i]);

        for (int x = sorted_index[i] + 1; x < n+10; x += x&-x) tree[x]++;

        if (sorted_index[i] >= freefall) {
            // dbg(seg.query(0,n-1).sm);
            // dbg(freefall, sorted_index[i]);
            seg.upd(freefall, sorted_index[i], update(1));
            // dbg(sorted_index[i], a[i] + (i - get(sorted_index[i])));
            seg.upd(sorted_index[i], sorted_index[i], {0, a[i] + (i - get(sorted_index[i]))});

            // dbg(seg.query(0,n-1).sm);
        }

        while (true) {
            auto ff = indices.lower_bound(freefall);
            if (ff == indices.begin()) break;
            --ff;

            int bef = get(*ff);
            if (sorted[*ff].first < -bef) break;
            
            freefall = *ff;
            // dbg(freefall, sorted[freefall].first + (i - bef));
            seg.upd(freefall, freefall, {0, sorted[freefall].first + (i - bef)});
        }

        int before_ff = get(freefall);
        // dbg(freefall, (i+1) - 2*before_ff, seg.query(freefall, n-1).sm);
        cout << min((i+1) - 2*before_ff, seg.query(freefall, n-1).sm) << '\n';
    }


    return 0;
}