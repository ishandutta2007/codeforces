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
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod*mod;
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

void solve() {
	int x; cin >> x;
	int t = 0;
	vector<int> ans;
	rep(j, 19) {
		if (x&(1 << j)) {
			ans.push_back(j); t += 2;
			x ^= (1 << j) - 1; x++;
		}
	}
	t++;
	if (x == (1 << 19)) {
		ans.push_back(19); x ^= (1 << 19) - 1;
	}
	else {
		ans.push_back(20); x ^= (1 << 20) - 1;
	}
	cout << t << endl;
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	if(ans.size())cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}