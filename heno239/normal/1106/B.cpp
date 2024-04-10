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
int n,m;
ll a[1 << 17], c[1 << 17];
priority_queue<LP,vector<LP>,greater<LP>> q;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> c[i];
		q.push({ c[i],i });
	}
	rep(i, m) {
		int t; ll d; cin >> t >> d; t--;
		ll ans = 0;
		ll mi = min(d, a[t]);
		ans += mi * c[t];
		d -= mi; a[t] -= mi;
		while (d > 0) {
			if (q.empty()) {
				ans = 0; break;
			}
			LP p = q.top();
			mi = min(d, a[p.second]);
			ans += mi * c[p.second];
			d -= mi; a[p.second] -= mi;
			if (a[p.second] == 0)q.pop();
		}
		cout << ans << endl;
	}
	//stop
	return 0;
}