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

vector<int> G[1 << 20];
bool used[1 << 20];
void solve() {
	int n, m; cin >> n >> m;
	vector<int> u(m),v(m);
	vector<int> d(n);
	vector<int> s(n);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
		d[u[i]]++; d[v[i]]++;
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	set<P> st;
	rep(i, n) {
		s[i] = d[i] - (d[i] + 1) / 2;
		st.insert({ s[i],i });
	}
	vector<P> ans;
	rep(i, n) {
		auto itr = st.end(); itr--;
		P p = *itr; st.erase(itr);
		int id = p.second;
		used[id] = true;
		vector<P> v;
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (used[to])continue;
			v.push_back({ s[to],to });
		}
		sort(v.begin(), v.end(), greater<P>());
		int len = v.size();
		len = min(len, s[id]);
		rep(j, len) {
			//...
			int to = v[j].second;
			if (s[to] > 0) {
				st.erase(P{ s[to],to });
				s[to]--;
				st.insert({ s[to],to });
			}
			else {
				ans.push_back({ id,to });
			}
		}
		Rep(j, len, v.size()) {
			//
			ans.push_back({ id,v[j].second });
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second+1 << endl;
	}
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