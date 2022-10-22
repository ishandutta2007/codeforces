#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////
// Templated Segment Tree -- O(log(n)) per reasonable query
// Warning: possibly SLOW! because Node is copied when querying
//
// USAGE:
// 	SegmentTree<Node,T> magic(length);
// 	magic.set(i,v); sets ith value to v, DOES NOT PULL
// 	magic.build(); pulls leaves up
// 	magic.query(l,r); range [l,r], combines segments using pull
// 	magic.update(l,r,v); range [l,r], updates with v
// 
// The Node class requires the following: (SEE EXAMPLE BELOW)
// Node();
//  The default constructor that is called initially, and when a query
//  range is out of bounds.
// Node(T v);
//  The constructor that is called in set(int i, T v);
// bool put(T v);
//  The break condition when updating. For normal queries, return true.
// bool get();
//  The break condition when querying. For normal queries, return true.
// void update(T v, int len);
//  Used to update the Node with value v at a segment with length len.
// void push(Node& left, Node& right, int len);
//  Used to lazy propagate from current node with length len to left 
//  and right children.
// Node pull(Node left, Node right);
//  Used to update current node from left and right children.
//*!
template <class Node, class T>
struct SegmentTree {
    int n;
    vector<Node> segt;
    SegmentTree(int len=3e5+1) {
        n = 1 << (32 - __builtin_clz(len-1));
        segt.resize(2*n);
    }
    void set(int i, const T& v) {
        segt[n+i] = Node(v);
    }
    void build() {
        for (int i = n-1; i > 0; i--) {
            segt[i].pull(segt[2*i], segt[2*i+1]);
        }
    }
    void update(int l, int r, const T& v) {
        update(l, r, v, 1, 0, n-1);
    }
    void update(int l, int r, const T& v, int i, int s, int e) {
        if (e < l || s > r) return;
        if (l <= s && e <= r && segt[i].put(v)) {
            segt[i].update(v, e-s+1);
            // if (i<n) segt[i].pull(segt[2*i], segt[2*i+1]);
            return;
        }
        segt[i].push(segt[2*i], segt[2*i+1], e-s+1);
        int m = (s + e) / 2;
        update(l, r, v, 2*i, s, m);
        update(l, r, v, 2*i+1, m+1, e);
        segt[i].pull(segt[2*i], segt[2*i+1]);
    }
    Node query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }
    Node query(int l, int r, int i, int s, int e) {
        if (e < l || s > r) return Node();
        if (l <= s && e <= r && segt[i].get()) {
            return segt[i];
        }
        segt[i].push(segt[2*i], segt[2*i+1], e-s+1);
        int m = (s + e) / 2;
        return Node().pull(query(l, r, 2*i, s, m), query(l, r, 2*i+1, m+1, e));
    }
};
//*/

struct Node {
	ll v, z;
	Node(ll x=-INFLL): v(x), z(0) {}
	bool get() { return true; }
	bool put(const ll& x) { return true; }
	void update(ll x, int len) {
		v += x;
		z += x;
	}
	void push(Node& left, Node& right, int len) {
		if (z) {
			left.v += z;
			left.z += z;
			right.v += z;
			right.z += z;
			z = 0;
		}
	}
	const Node& pull(const Node& left, const Node& right) {
		v = max(left.v, right.v);
		return *this;
	}
};

SegmentTree<Node,ll> segt[10];

const int N = 3e5+1;
int a[N];
ll p[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m; ll k;
	cin >> n >> m >> k;

	FOR(i,1,n) {
		cin >> a[i];
		p[i] = p[i-1] + a[i];
		segt[i%m].set(i, p[i] - k*((i+m-1)/m));
	}
	For(i,m) {
		segt[i].build();
	}

	ll ans = 0;
	FOR(i,1,n) {
		For(j,m) {
			ans = max(ans, segt[j].query(i,n).v - p[i-1]);
		}
		segt[i%m].update(i, n, k);
	}
	cout << ans << nl;

	return 0;
}