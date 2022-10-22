#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
//#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int bruteforce(vector<int> a) {
	int n = sz(a);
	vector<int> dp(n, 1);
	dp[n-1] = 1;
	int ans = 1;
	rrep(i,n-1,0) {
		rep(j,i+1,min(n, i+1100)) {
			if ((a[i]^j) < (a[j]^i)) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(ans, dp[i]);
	}
#ifndef DEBUG
	cout << ans << endl;
#endif
	return ans;
}
 
struct Key {
	int b;
	bool b_bit;
	int higher_order;
 
	bool operator<(const Key& other) const {
		if (higher_order != other.higher_order)
			return higher_order < other.higher_order;
		if (b != other.b)
			return b < other.b;
		return b_bit < other.b_bit;
	}
 
	ll to_key() {
		return ((((ll)higher_order))<<30) + b * 16 + (b_bit ? 1 : 0);
	}
};

struct Node {
	Node* children[2];
	int val[2];

	Node() {
		rep(i,0,2) {
			children[i] = NULL;
			val[i] = 0;
		}
	}

	Node* get_child(bool x) {
		if (!children[x])
			children[x] = new Node();
		return children[x];
	}

	~Node() {
		rep(i,0,2)
			if (children[i])
				delete children[i];
	}
};
 
int solve(vector<int> a) {
	int n = sz(a);
	//unordered_map<ll, int> dp;
	int ans = 1;
	Node root;
	rrep(i,n,0) {
		int best_val = 1;
		Node* v = &root;
		rrep(b,31,0) {
			bool c = (a[i]^i)&(1<<b);
			best_val = max(best_val, v->get_child(!c)->val[(a[i]&(1<<b)) ? 1 : 0]+1);
			v = v->get_child(c);
		}
		v = &root;
		rrep(b,31,0) {
			bool c = (a[i]^i)&(1<<b);
			v = v->get_child(c);
			int& y = v->val[(i&(1<<b)) ? 1 : 0];
			y = max(y, best_val);
		}
		/*rep(b,0,30) {
			Key k;
			k.b = b;
			k.b_bit = a[i]&(1<<b);
			k.higher_order = ((a[i]^i)&(~((1<<b)-1)))^(1<<b);
			best_val = max(best_val, dp[k.to_key()]+1);
		}
		rep(b,0,30) {
			Key k;
			k.b = b;
			k.b_bit = i&(1<<b);
			k.higher_order = (a[i]^i)&(~((1<<b)-1));
			ll x = k.to_key();
			int& y = dp[x];
			y = max(y, best_val);
		}*/
		ans = max(ans, best_val);
	}
#ifndef DEBUG
	cout << ans << endl;
#endif
	return ans;
}
 
int main() {
#ifdef DEBUG
	//while (true) {
	int n = 300000;
	vector<int> a(n);
	rep(i,0,n) {
		a[i] = rand()%1000000000;
	}
	solve(a);
	return 0;
	/*assert(solve(a) == bruteforce(a));
	cerr << "Ok" << endl;
	}*/
#endif
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i,0,n)
			cin >> a[i];
		solve(a);
	}
}