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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

set<int> st[26];
bool exi(int k, int l, int r) {
	if (st[k].count(l))return true;
	st[k].insert(l);
	auto itr = st[k].find(l);
	itr++;
	int val = *itr;
	st[k].erase(l);
	return val <= r;
}
void solve() {
	string s; cin >> s;
	int n = s.size();
	rep(i, n) {
		st[s[i] - 'a'].insert(i);
	}
	rep(i, 26)st[i].insert(n);
	int q; cin >> q;
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int loc; char c;
			cin >> loc >> c;
			loc--;
			st[s[loc] - 'a'].erase(loc);
			st[c - 'a'].insert(loc);
			s[loc] = c;
		}
		else {
			int l, r; cin >> l >> r; l--; r--;
			int ans = 0;
			rep(i, 26)if (exi(i,l,r))ans++;
			cout << ans << endl;
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}