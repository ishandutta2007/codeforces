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

void solve() {
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	int ans = mod;
	rep(i, m - n + 1) {
		string u = t.substr(i, n);
		int cnt = 0;
		rep(j, n) {
			if (s[j] != u[j])cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	rep(i, m - n + 1) {
		string u = t.substr(i, n);
		int cnt = 0;
		rep(j, n) {
			if (s[j] != u[j])cnt++;
		}
	
		if (ans == cnt) {
			bool f = false;
			rep(j, n) {
				if (s[j] != u[j]) {
					if (f)cout << " ";
					else f = true;
					cout << j + 1;
				}
			}
			cout << endl;
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}