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
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

struct Node {
	Node *lch, *rch;
	int val;
	//

	Node() : lch(NULL), rch(NULL),val(0) {}
};
void add(Node* node, const int &s) {
	for (int i = 30; i >= 0;i--) {
		if (!(s&(1<<i))) {
			if (node->lch == NULL) node->lch = new Node();
			node = node->lch;
		}
		else {
			if (node->rch == NULL) node->rch = new Node();
			node = node->rch;
		}
		node->val++;
	}
}
int k; int n;
int dfs(Node* node,const int &s) {
	int res = n+1;
	for (int i = 30; i >= 0; i--) {
		bool bs = s & (1 << i);
		bool bk = k & (1 << i);
		if (bs&&bk) {
			if (node->rch != NULL)res -= node->rch->val;
			if (node->lch == NULL)break;
			else node = node->lch;
		}
		else if (bs) {
			if (node->rch == NULL)break;
			else node = node->rch;
		}
		else if (bk) {
			if (node->lch != NULL)res -= node->lch->val;
			if (node->rch == NULL)break;
			else node = node->rch;
		}
		else {
			if (node->lch == NULL)break;
			else node = node->lch;
		}
	}
	return res;
}
int a[1 << 20];
int ss[1 << 20];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	Node* m = new Node();
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		ss[i + 1] = ss[i] ^ a[i];
	}
	rep(i, n + 1) {
		add(m, ss[i]);
	}
	ll out = 0;
	rep(i, n+1) {
		out += dfs(m, ss[i]);
		//cout << ss[i] << endl;
		//cout << out << endl;
	}
	cout << out / 2 << endl;
	return 0;
}