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

const int m = 26 * 26 * 26;
vector<int> loc[m];
bool used[m];

vector<P> v;
vector<int> ans;
void solve() {
	int n; cin >> n; ans.resize(n);
	rep(i, n) {
		string s, t; cin >> s >> t;
		int x = s[0] - 'A', y = s[1] - 'A', z = s[2] - 'A';
		int zz = t[0] - 'A';
		x *= 26 * 26;
		y *= 26;
		loc[x + y + z].push_back(x + y + zz);
		v.push_back({ x + y + z,x + y + zz });
	}
	queue<int> q;
	rep(i, n) {
		if (loc[v[i].first].size() >= 2) {
			used[v[i].first] = true;
			used[v[i].second] = true;
			ans[i] = v[i].second;
		}
		else {
			q.push(i);
		}
	}
	while(!q.empty()){
		bool f = false;
		int len = q.size();
		rep(i, len) {
			int id = q.front(); q.pop();
			if (used[v[id].first]) {
				used[v[id].second] = true;
				ans[id] = v[id].second;
				f = true;
			}
			else q.push(id);
		}
		if (!f) {
			while (!q.empty()) {
				int id = q.front(); q.pop();
				ans[id] = v[id].first;
			}
			break;
		}
	}
	rep(i, n) {
		Rep(j, i + 1, n) {
			if (ans[i] == ans[j]) {
				cout << "NO" << endl; return;
			}
		}
	}
	cout << "YES" << endl;
	rep(i, n) {
		string str;
		rep(j, 3) {
			str.push_back('A' + (ans[i] % 26)); ans[i] /= 26;
		}
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}