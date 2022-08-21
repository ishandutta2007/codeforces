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
	int s[3];
	int e[3];
	int c[3];
	rep(i, 3)cin >> s[i];
	rep(i, 3)cin >> e[i];
	rep(i, 3)cin >> c[i];
	int ans = mod;
	rep(i, 201) {
		rep(j, 201) {
			int sum = c[1] * i + c[2] * j;
			int decs = max(0, e[1] - s[2] - j);
			int dece = max(0, s[1] + i - e[2]);
			if (dece==0)continue;
			int t = (e[0] + dece - 1) / dece;
			int needhp = t * decs + 1;
			int dif = needhp - s[0];
			if (dif > 0) {
				sum += dif * c[0];
			}
			ans = min(ans, sum);
		}
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