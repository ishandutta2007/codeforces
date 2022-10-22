#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

struct Node {
	int l, r, v;

	Node(int L, int R, int V) {
		l = L;
		r = R;
		v = V;
	}
};

struct pst {
	int n;
	vector<Node> tree;
	vector<int> root;

	pst(int k) {
		n = k;
		root.resize(n+1, 0);
		tree.eb(0, 0, 0);
	}

	void expand(int node, int s, int e, int i, int pnd, int cnd) {
		if(s == e) {
			tree[cnd].v = tree[pnd].v+1;
			return;
		}

		int m = s+e>>1;
		if(i <= m) {
			tree[cnd].r = tree[pnd].r;
			tree[cnd].l = tree.size();
			tree.eb(0, 0, 0);
			expand(node*2, s, m, i, tree[pnd].l, tree[cnd].l);
		}
		else {
			tree[cnd].l = tree[pnd].l;
			tree[cnd].r = tree.size();
			tree.eb(0, 0, 0);
			expand(node*2+1, m+1, e, i, tree[pnd].r, tree[cnd].r);
		}

		tree[cnd].v = tree[tree[cnd].l].v + tree[tree[cnd].r].v;
	}

	int sum(int node, int s, int e, int l, int r, int pnd, int cnd) {
		if(r < s || e < l) return 0;
		if(l <= s && e <= r) return tree[cnd].v - tree[pnd].v;

		int m = s+e>>1;
		return sum(node*2, s, m, l, r, tree[pnd].l, tree[cnd].l) + sum(node*2+1, m+1, e, l, r, tree[pnd].r, tree[cnd].r);
	}
};

int n;
vector<pair<pii,pii>> v, v2;

int main() {
	fast;

	cin >> n;

	pst L(n), R(n), L2(n), R2(n);

	for(int i=1; i<=n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		v.pb({{a, b}, {c, d}});
		v2.pb({{c, d}, {a, b}});
	}

	sort(all(v));

	for(int i=0; i<n; i++) {
		L.root[i+1] = L.tree.size();
		L.tree.eb(0, 0, 0);
		L.expand(1, 0, inf+1, v[i].se.fi, L.root[i], L.root[i+1]);
		R.root[i+1] = R.tree.size();
		R.tree.eb(0, 0, 0);
		R.expand(1, 0, inf+1, v[i].se.se, R.root[i], R.root[i+1]);
	}

	for(int i=0; i<v.size(); i++) {
		int t = upper_bound(all(v), mp(mp(v[i].fi.se, inf), mp(inf, inf))) - v.begin() - 1;
		
		int sum = L.sum(1, 0, inf+1, v[i].se.se+1, inf+1, L.root[i+1], L.root[t+1]) + R.sum(1, 0, inf+1, 0, v[i].se.fi-1, R.root[i+1], R.root[t+1]);
		if(sum > 0) {
			cout << "NO";
			return 0;
		}
	}

	sort(all(v2));

	for(int i=0; i<n; i++) {
		L2.root[i+1] = L2.tree.size();
		L2.tree.eb(0, 0, 0);
		L2.expand(1, 0, inf+1, v2[i].se.fi, L2.root[i], L2.root[i+1]);
		R2.root[i+1] = R2.tree.size();
		R2.tree.eb(0, 0, 0);
		R2.expand(1, 0, inf+1, v2[i].se.se, R2.root[i], R2.root[i+1]);
	}

	for(int i=0; i<v2.size(); i++) {
		int t = upper_bound(all(v2), mp(mp(v2[i].fi.se, inf), mp(inf, inf))) - v2.begin() - 1;
		
		int sum = L2.sum(1, 0, inf+1, v2[i].se.se+1, inf+1, L2.root[i+1], L2.root[t+1]) + R2.sum(1, 0, inf+1, 0, v2[i].se.fi-1, R2.root[i+1], R2.root[t+1]);
		if(sum > 0) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}