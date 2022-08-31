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
#define fr first
#define sc second

vector<int> v = { 0,0,1,2,0,2,1 };
void solve() {
	ll a[3]; rep(i, 3)cin >> a[i];
	ll mi = min({ a[0] / 3,a[1] / 2,a[2] / 2 });
	ll ans = mi * 7; a[0] -= mi * 3; a[1] -= mi * 2; a[2] -= mi * 2;
	ll out = 0;
	rep(i, 7) {
		ll r[3]; rep(i, 3)r[i] = a[i];
		ll cop = ans;
		int cur = i;
		while (true) {
			//cout << i << " " << cur << endl;
			if (r[v[cur]] > 0) {
				r[v[cur]]--; cop++;
				cur = (cur + 1) % 7;
			}
			else break;
		}
		//cout << cop << endl;
		out = max(out, cop);
	}
	cout << out << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}