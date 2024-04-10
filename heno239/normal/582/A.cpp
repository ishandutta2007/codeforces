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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

int cnt[1 << 19];
void solve() {
	int n; cin >> n;
	vector<int> v;
	rep(i, n*n) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	vector<int> u;
	rep(i, v.size()) {
		int le = i;
		while (i + 1 < v.size() && v[i + 1] == v[i])i++;
		int len = i - le + 1;
		cnt[u.size()] = len;
		u.push_back(v[i]);
	}
	vector<int> ans;
	per(i, u.size()) {
		if (cnt[i] == 0)continue;
		cnt[i]--;
		rep(j, ans.size()) {
			int g = gcd(ans[j], u[i]);
			g = lower_bound(u.begin(), u.end(), g) - u.begin();
			cnt[g] -= 2;
		}
		ans.push_back(u[i]);
		if (cnt[i])i++;
	}
	rep(i, n) {
		if(i>0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}