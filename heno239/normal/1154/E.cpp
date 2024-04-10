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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

set<int> st;

bool used[1 << 18];
int inva[1 << 18];

string ans;
void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		inva[a[i]] = i;
		st.insert(i);
	}
	ans.resize(n);
	int id = 0; int ma = n;
	while (true) {
		while (ma > 0 && used[inva[ma]])ma--;
		if (ma == 0)break;
		int loc = inva[ma];
		auto itr = st.find(loc);
		ans[loc] = '1' + id;
		auto itr2 = itr;
		vector<int> v = {loc};
		rep(i, k) {
			if (itr == st.begin())break;
			itr--;
			int u = *itr;
			ans[u] = '1' + id;
			v.push_back(u);
		}
		itr = itr2;
		rep(i, k) {
			itr++;
			if (itr == st.end())break;
			int u = *itr;
			ans[u] = '1' + id;
			v.push_back(u);
		}
		rep(i, v.size()) {
			st.erase(v[i]); used[v[i]] = true;
		}
		id ^= 1;
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}