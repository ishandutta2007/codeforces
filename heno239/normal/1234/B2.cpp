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

void solve() {
	int n, k; cin >> n >> k;
	map<int, bool> exi;
	deque<int> deq;
	rep(i, n) {
		int a; cin >> a;
		if (exi[a])continue;
		if (deq.size() == k) {
			int p = deq.back();
			exi[p] = false;
			deq.pop_back();
		}
		exi[a] = true;
		deq.push_front(a);
	}
	vector<int> ans;
	while (!deq.empty()) {
		ans.push_back(deq.front()); deq.pop_front();
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}