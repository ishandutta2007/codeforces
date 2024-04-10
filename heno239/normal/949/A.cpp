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
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void solve() {
	string s; cin >> s;
	int n = s.size();
	set<int> zeros, ones;
	rep(i, n) {
		if (s[i] == '0') {
			zeros.insert(i);
		}
		else {
			ones.insert(i);
		}
	}
	vector<vector<int>> ans;
	while (zeros.size() || ones.size()) {
		vector<int> ids;
		if (zeros.empty()) {
			cout << -1 << endl; return;
		}
		int cur = *zeros.begin();
		ids.push_back(cur);
		zeros.erase(cur);
		while (true) {
			ones.insert(cur);
			auto itr = ones.find(cur);
			itr++;
			if (itr == ones.end()) {
				ones.erase(cur);
				break;
			}
			else {
				int nex = *itr;
				ids.push_back(nex);
				ones.erase(nex);
				ones.erase(cur);
				zeros.insert(nex);
				auto itr2 = zeros.find(nex);
				itr2++;
				if (itr2 == zeros.end()) {
					cout << -1 << endl; return;
				}
				cur = *itr2;
				ids.push_back(cur);
				zeros.erase(cur);
				zeros.erase(nex);
			}
		}
		ans.push_back(ids);
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].size();
		rep(j, ans[i].size()) {
			int id = ans[i][j] + 1;
			cout <<" "<< id;
		}
		cout << endl;
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}