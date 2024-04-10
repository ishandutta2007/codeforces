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
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

vector<int> G[26];
int c[26];

string ans;

void solve() {
	int n; cin >> n;
	vector<string> v(n);
	rep(i, n)cin >> v[i];
	rep(i, n) {
		Rep(j, i + 1, n) {
			int len = min(v[i].size(), v[j].size());
			if (v[i].size() > v[j].size()) {
				string u = v[i].substr(0, len);
				if (u == v[j]) {
					cout << "Impossible" << endl; return;
				}
			}
			rep(k, len) {
				if (v[i][k] != v[j][k]) {
					int l = v[i][k] - 'a';
					int r = v[j][k] - 'a';
					G[l].push_back(r); c[r]++;
					break;
				}
			}
		}
	}
	queue<int> q;
	rep(i, 26) {
		if (c[i] == 0) {
			q.push(i); c[i]--;
		}
	}
	while (!q.empty()) {
		int id = q.front(); q.pop();
		ans.push_back('a' + id);
		rep(j, G[id].size()) {
			int to = G[id][j];
			c[to]--;
			if (c[to] == 0) {
				q.push(to); c[to]--;
			}
		}
	}
	if (ans.size() != 26) {
		cout << "Impossible" << endl;
	}
	else {
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}