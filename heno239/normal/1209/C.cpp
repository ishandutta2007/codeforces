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
#include<complex>
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

void solve() {
	vector<int> v[10];
	int n; cin >> n;
	string s; cin >> s;
	rep(i, n) {
		v[s[i] - '0'].push_back(i);
	}
	vector<bool> used(n, false);
	int le = 0;
	vector<int> memo;
	rep(i, 10) {
		if (v[i].empty())continue;
		if (v[i][0] < le) {
			rep(j, v[i].size()) {
				if (v[i][j] >= le) {
					used[v[i][j]] = true;
					memo.push_back(s[v[i][j]] - '0');
				}
			}
			break;
		}
		else {
			rep(j, v[i].size()) {
				used[v[i][j]] = true;
				memo.push_back(s[v[i][j]] - '0');
			}
			le = v[i].back() + 1;
		}
	}
	rep(i, n) {
		if (!used[i]) {
			memo.push_back(s[i]-'0');
		}
	}
	//cout << "ans is ";
	rep(i, (int)memo.size() - 1) {
		if (memo[i] > memo[i + 1]) {
			//cout << memo[i] << " " << memo[i + 1] << endl;
			cout << '-' << endl; return;
		}
	}
	rep(i, n) {
		if (used[i])cout << "1";
		else cout << "2";
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}

	//cout << "finish" << endl;
	//stop
	return 0;
}