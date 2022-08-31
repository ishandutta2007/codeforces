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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

//

struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

int n;
//
vector<int> calc(vector<int> &p) {
	vector<int> ret(n);
	BIT b(n);
	rep(i, n) {
		//
		int id = p[i] - b.sum(p[i]);
		ret[i] = id;
		b.add(p[i], 1);
	}
	return ret;
}

//x
vector<int> rev(vector<int> &x) {
	BIT b(n);
	vector<int> ret(n);
	rep(i, n) {
		//x[i]
		//log2
		int le = 0, ri = n;
		while (ri - le > 1) {
			int mid = (le + ri) / 2;
			if (mid-1-b.sum(mid) < x[i])le = mid;
			else {
				ri = mid;
			}
		}
		ret[i] = le;
		b.add(le, 1);
	}
	return ret;
}
void solve() {
	cin >> n;
	vector<int> p(n), q(n);
	rep(i, n) {
		cin >> p[i];
	}
	vector<int> sp = calc(p);
	rep(i, n) {
		cin >> q[i];
	}
	vector<int> sq = calc(q);
	int c = 0;
	vector<int> sum(n);
	for (int i = n - 1; i >= 0; i--) {
		c += sp[i]; c += sq[i];
		sum[i] = c % (n - i);
		c /= (n - i);
	}
	vector<int> ans = rev(sum);
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}