#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

const int digits= 30;
struct Node {
	Node *lch, *rch;
	vector<int> ids;
	//

	Node() : lch(NULL), rch(NULL) {}
};
void add(Node* node, const int &s, int id) {
	per(i, digits) {
		int d = (1 << i);
		if (d&s) {
			if (node->rch == NULL)node->rch = new Node();
			node = node->rch;
		}
		else {
			if (node->lch == NULL)node->lch = new Node();
			node = node->lch;
		}
		node->ids.push_back(id);
	}
}
bool in(Node* node, int le, int ri) {
	if (node == NULL)return false;
	int id = lower_bound(node->ids.begin(), node->ids.end(), le) - node->ids.begin();
	if (id == node->ids.size())return false;
	if (node->ids[id] >= ri)return false;
	return true;
}
int dfs(Node* node, int s, int le, int ri) {
	int res = 0;
	per(i, digits) {
		int d = (1 << i);
		if (s&d) {
			if (in(node->rch,le,ri)) {
				node = node->rch;
			}
			else {
				res += d;
				node = node->lch;
			}
		}
		else {
			if (in(node->lch,le,ri)) {
				node = node->lch;
			}
			else {
				res += d;
				node = node->rch;
			}
		}
	}
	return res;
}
Node* nd;
int n; vector<int> a;
ll calc(int l, int r, int k) {
	int ri = r;
	ll res = 0;
	per(i, 30) {
		int d = (1 << i);
		int le = lower_bound(a.begin() + l, a.begin() + r, k + d) - a.begin();
		if (le >= ri)continue;
		res += calc(le, ri, d + k);
		if (le != l) {
			int mi = 1 << 30;
			Rep(j, le, ri) {
				mi = min(mi, dfs(nd, a[j] ^ d, l, le));
			}
			res += mi + d;
		}
		ri = le;
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n; a.resize(n);
	nd = new Node();
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	rep(i, n) {
		add(nd, a[i], i);
	}
	cout << calc(0, n, 0) << endl;
	return 0;
}