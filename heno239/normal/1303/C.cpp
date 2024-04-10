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
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



void solve() {
	string s; cin >> s;

	vector<int> loc(26, -1);
	vector<bool> exi(200, false);
	loc[s[0] - 'a'] = 100; exi[100] = true;
	int len = s.size();
	rep(i, len - 1) {
		int fr = s[i] - 'a';
		int sc = s[i+1] - 'a';
		if (loc[sc] < 0) {
			if (!exi[loc[fr] + 1]) {
				loc[sc] = loc[fr] + 1;
				exi[loc[sc]] = true;
			}
			else if (!exi[loc[fr] - 1]) {
				loc[sc] = loc[fr] - 1;
				exi[loc[sc]] = true;
			}
			else{
				cout << "NO" << endl; return;
			}
		}
		else {
			if (abs(loc[sc] - loc[fr]) != 1) {
				cout << "NO" << endl; return;
			}
		}
	}
	vector<P> v;
	rep(i, 26)v.push_back({ loc[i],i });
	sort(all(v));
	string ans;
	rep(i, v.size()) {
		ans.push_back('a' + v[i].second);
	}
	cout << "YES" << endl;
	cout << ans << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;rep(i,t) solve();
	//solve();
	stop
		return 0;
}