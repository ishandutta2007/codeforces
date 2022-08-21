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
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

vector<int> l[27],r[27];
vector<P> ans;
void solve() {
	int n; cin >> n;
	string a, b; cin >> a >> b;
	rep(i, n) {
		if (a[i] == '?') {
			l[26].push_back(i);
		}
		else {
			l[a[i] - 'a'].push_back(i);
		}
		if (b[i] == '?') {
			r[26].push_back(i);
		}
		else {
			r[b[i] - 'a'].push_back(i);
		}
	}
	rep(i, 26) {
		rep(j, l[i].size()) {
			if (!r[i].empty()) {
				ans.push_back({ l[i][j],r[i].back() });
				r[i].pop_back();
			}
			else {
				if (!r[26].empty()) {
					ans.push_back({ l[i][j],r[26].back() });
					r[26].pop_back();
				}
			}
		}
	}
	rep(j, l[26].size()) {
		rep(i, 27) {
			if (!r[i].empty()) {
				ans.push_back({ l[26][j],r[i].back() });
				r[i].pop_back();
				break;
			}
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second+1 << endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}