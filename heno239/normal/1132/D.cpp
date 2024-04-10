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
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int n, k;
ll a[1 << 18], b[1 << 18];
ll c[1 << 18];
bool can(ll x) {
	priority_queue<LP,vector<LP>,greater<LP>> q;
	fill(c, c + n, 0);
	rep(i, n) {
		ll d = a[i] / b[i];
		q.push({ d,i });
	}
	rep(i, k) {
		LP p = q.top(); q.pop();
		if (p.first - i < 0) {
			return false;
		}
		else if (p.first >= k - 1)return true;
		int id = p.second;
		c[id] += x;
		ll sum = a[id] + c[id];
		q.push({ sum / b[id], id });
	}
	//cout << x << " " << q.top().first << endl;
	//if (q.top().first < k)return false;
	return true;
}
void solve() {
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n)cin >> b[i];
	ll le = -1, ri = INF;
	while (ri - le > 1) {
		ll mid = (ri + le) / 2;
		if (can(mid))ri = mid;
		else le = mid;
	}
	if (ri == INF)ri = -1;
	cout << ri << endl;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}