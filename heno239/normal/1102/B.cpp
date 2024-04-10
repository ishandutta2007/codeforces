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
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int a[5000];
vector<int> v[5001];
int ans[5000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	bool valid = true;
	int cur = 0;
	rep1(i, 5000) {
		if (v[i].size() > k) {
			valid = false; break;
		}
		rep(j, v[i].size()) {
			ans[v[i][j]] = cur;
			cur = (cur + 1) % k;
		}
	}
	if (valid) {
		cout << "YES" << endl;
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << ans[i]+1;
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}
	//stop
		return 0;
}