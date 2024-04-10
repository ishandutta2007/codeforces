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
	vector<int> v;
	rep(i, s.size())if (s[i] == '1')v.push_back(i);
	if (v.empty()) {
		cout << 0 << endl; return;
	}
	int le = v[0]; int ri = v.back();
	int ans = 0;
	for (int i = le; i <= ri; i++)if (s[i] == '0')ans++;
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