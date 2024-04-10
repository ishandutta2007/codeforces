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

void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	ll ans = 0;
	vector<ll> v;
	vector<char> t;
	ll sum = 0;
	rep(i, n) {
		int le = i;
		while (i + 1 < n&&s[i] == s[i + 1])i++;
		ll len = i - le + 1;
		v.push_back(len);
		t.push_back(s[i]);
		sum += len * (len + 1) / 2;
	}
	rep(i, v.size()) {
		
		ans += n * (m - 1);
	}

	rep(i, n - 1) {
		ll tmp = 1;
		char x[2] = { s[i],s[i + 1] };
		if (x[0] == x[1])continue;
		int j = i + 2;
		int id = 0;
		while (j < n&&s[j] == x[id]) {
			tmp++; j++;
			id ^= 1;
		}
		i = j - 2;
		ans -= tmp * (tmp + 1) / 2;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}