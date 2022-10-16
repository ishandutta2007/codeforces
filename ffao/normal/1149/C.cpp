#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

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
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

struct LazyContext {
	LazyContext(int val=0) : val(val) {}
	void reset() { *this = LazyContext(); }
	void operator += (LazyContext o) { val += o.val; }
	
	// atributes
    int val;
};

// Range update, range query segment tree
struct Node {
    int ma;
    int mb;
    int mab;
    int mc;
    int mbc;
    int mabc;

	Node() {
		ma=mb=mab=mc=mbc=mabc=-1000000000;
	}

    Node(int v) {
        ma=mc=v;
        mb=-2*v;
        mab=mbc=-v;
        mabc=0;
    }
	
	Node(Node &l, Node &r) {
		ma = max(l.ma, r.ma);
        mb = max(l.mb, r.mb);
        mab = max(l.ma + r.mb, max(l.mab, r.mab));
        mc = max(l.mc, r.mc);
        mbc = max(l.mb + r.mc, max(l.mbc, r.mbc));
        mabc = max(max(l.ma + r.mbc, l.mab + r.mc), max(l.mabc,r.mabc));
	}
	
	void apply(LazyContext lazy) {
		ma += lazy.val;
        mb -= 2*lazy.val;
        mab -= lazy.val;
        mc += lazy.val;
        mbc -= lazy.val;
	}
};

template <class i_t, class e_t, class lazy_cont = int>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		h = 0;
		while((1 << h) < n) h++;
		tree.resize(2 * n);
		dirty.assign(n, false);
		lazy.resize(n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
			lazy[i].reset();
		}
	}
	
	i_t qry(int l, int r) {
		if(l >= r) return i_t();
		l += n, r += n;
		push(l);
		push(r - 1);
		i_t lp, rp;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int l, int r, lazy_cont lc) {
		if(l >= r) return;
		l += n, r += n;
		push(l);
		push(r - 1);
		int l0 = l, r0 = r;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, lc);
			if(r & 1) apply(--r, lc);
		}
		build(l0);
		build(r0 - 1);
	}
	
	template<class F>
	int search(int l, int r, F f) {
		assert(l <= r);
		int lst = r;
		l += n, r += n;
		push(l);
		push(r-1);
		int pref[h+1], suf[h+1], s[2] = {0, 0}; // depending on compiler might want to change pref and suf to vectors, resize(h+1) and push_back below
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) pref[s[0]++] = l++;
			if(r & 1) suf[s[1]++] = --r;
		}
		std::reverse(suf, suf + s[1]);
		i_t cur;
		for(int rep = 0; rep < 2; rep++) {
			for(int id = 0; id < s[rep]; id++) {
				int i = rep == 0 ? pref[id] : suf[id];
				if(f(i_t(cur, tree[i]))) {
					while(i < n) {
						pushNode(i);
						i += i;
						i_t other = i_t(cur, tree[i]);
						if(!f(other)) {
							cur = other;
							i++;
						}
					}
					return i - n;
				}
				cur = i_t(cur, tree[i]);
			}
		}
		return lst;
	}
private:
	int n, h;
	std::vector<bool> dirty;
	std::vector<i_t> tree;
	std::vector<lazy_cont> lazy;
	
	void apply(int p, lazy_cont &lc) {
		tree[p].apply(lc);
		if(p < n) {
			dirty[p] = true;
			lazy[p] += lc;
		}
	}
	
	void push(int p) {
		for(int s = h; s > 0; s--) {
			int i = p >> s;
			pushNode(i);
		}
	}

	inline void pushNode(int i) {
		if(dirty[i]) {
			apply(i + i, lazy[i]);
			apply(i + i + 1, lazy[i]);
			lazy[i].reset();
			dirty[i] = false;
		}
	}
	
	void build(int p) {
		for(p /= 2; p > 0; p /= 2) {
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
			if(dirty[p]) {
				tree[p].apply(lazy[p]);
			}
		}
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin >> n >> q;
    
    string s;
    cin >> s;
    n = sz(s);

    vector<int> ds;
    ds.push_back(0);
    for (int i = 0; i < n; i++) {
        ds.push_back(ds.back());
        if (s[i] == '(') ds.back()++;
        else ds.back()--;
    }

    dbg(ds);

    SegmentTree<Node, int, LazyContext> seg;
    seg.init(ds);

    cout << seg.qry(0, n+1).mabc << '\n';
    for (; q; q--) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        seg.upd(x, y, LazyContext(s[x-1] == '(' ? -2 : 2));
        swap(s[x-1], s[y-1]);
        cout << seg.qry(0, n+1).mabc << '\n';
    }

    return 0;
}