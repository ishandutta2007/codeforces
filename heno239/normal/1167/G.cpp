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
typedef int ll;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

void solve() {
	int n, d; cin >> n >> d;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	int m; cin >> m;
	rep(aa, m) {
		ld ans = 0;
		ll x; cin >> x;
		int id = lower_bound(a.begin(), a.end(), x) - a.begin();
		if (id == n) {
			ll dist = x - a[n - 1]-1;
			if (dist == 0)ans = pi / 2.0;
			else ans = -atan(-1 / (ld)dist);
		}
		else if(id==0){
			ll dist = a[0] - x;
			if (dist ==0)ans = pi / 2.0;
			else ans = -atan(-1 / (ld)dist);
		}
		else {
			int le = id - 1, ri = id;
			if (a[le] + 1 ==a[ri] && a[ri] == x) {
				ans = pi;
			}
			else {
				//???
				ll dist = a[ri] - x;
				//cout << dist << endl;
				if (dist == 0)ans = max(ans,pi / 2.0);
				else ans = max(ans,-atan(-1 / (ld)dist));
				dist = x-a[le]-1;
				if (dist == 0)ans = max(ans, pi / 2.0);
				else ans = max(ans, -atan(-1 / (ld)dist));
				//cout << ans << endl;
				ld mi = 1 / tan(ans / 2.0); mi += eps;
				//cout << x<<" "<<ans << endl;
				for (int i = le; i >= 0;i--) {
					ll dist = x - a[i] - 1;
					if (dist > mi)break;
					while (ri<n&&a[ri] - x<dist - 1)ri++;
					if (ri == n)break;
					ll dist2 = a[ri] - x;
					if (dist2 == dist || dist2-1 == dist) {
						if (dist2 == 0)ans = max(ans, pi / 2.0);
						else ans = max(ans, -2*atan(-1 / (ld)dist2));
						break;
					}
					else if (dist2 + 1 == dist) {
						if (dist == 0)ans = max(ans, pi / 2.0);
						else ans = max(ans, -2*atan(-1 / (ld)dist));
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	solve();
	//stop
	return 0;
}