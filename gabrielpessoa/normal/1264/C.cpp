#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int ms = 2e5+5;
const int mod = 998244353;

int fExp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

struct Node {
	Node() {
		// empty constructor
        up = 1;
        hi = 0;
        lo = 0;
	}
	
	Node(int a) {
		// init
        up = a;
        hi = 1;
        lo = (mod + 1 - a) % mod;
	}
	
	Node(Node l, Node r) {
		up = l.up * r.up % mod;
        lo = (l.lo + r.lo * l.up)% mod;
        hi = (l.hi + r.hi * l.up)% mod;
	}

	// atributes
    int up, hi, lo;
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
		}
	}
	
	i_t qry(int l, int r) {
		i_t lp, rp;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int pos, e_t v) {
		pos += n;
		tree[pos] = i_t(v);
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
private:
	int n;
	std::vector<i_t> tree;
};


SegmentTree<Node, int> seg;

int get(Node n) {
    return n.hi * fExp((mod + 1 - n.lo)%mod, mod-2) % mod;
}

set<int> ac;
int hel[ms];

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int op = fExp(100, mod-2);
    vector<int> a;
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x * op % mod);
    }
    seg.init(a);
    int ans = get(seg.qry(0, n));
    hel[0] = ans;
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;
        ac.insert(0); ac.insert(n);
        if(ac.count(x)) {
            ac.erase(x);
            auto e = ac.lower_bound(x);
            int hi = *e;
            e--;
            int lo = *e;
            ans = (((ans - hel[lo] - hel[x]) % mod) + mod)% mod;
            hel[lo] = get(seg.qry(lo, hi));
            ans = (ans + hel[lo]) % mod;
            cout << ans << '\n';
        } else {
            auto e = ac.lower_bound(x);
            int hi = *e;
            e--;
            int lo = *e;
            ac.insert(x);
            ans = (((ans - hel[lo]) % mod) + mod)% mod;
            hel[x] = get(seg.qry(x, hi));
            hel[lo] = get(seg.qry(lo, x));
            ans = (ans + hel[lo] + hel[x]) % mod;
            cout << ans << '\n';
        }
    }
}