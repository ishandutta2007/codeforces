#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll dist(ll x, ll y, ll a, ll b) {
	return abs(x-a) + abs(y-b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	ll x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	ll xs, ys, t;
	cin >> xs >> ys >> t;

	auto down = [=](ll rem, ll x, ll y, int i) {
		int res = 1;
		for(--i; i>=0; i--) {
			ll nx = (x-bx)/ax;
			ll ny = (y-by)/ay;
			rem -= dist(nx,ny,x,y);
			if(rem < 0) return res;
			res++;
			x = nx;
			y = ny;
		}
		return res;
	};

	auto up = [=](ll rem, ll x, ll y, int i) {
		int res = 1;
		for(++i; i<60; i++) {
			ll nx = ax*x + bx;
			ll ny = ay*y + by;
			rem -= dist(nx,ny,x,y);
			if(rem < 0) return res;
			res++;
			x = nx;
			y = ny;
		}
		return res;
	};

	int ans = 0;
	for(int i=0; i<60; i++) {
		ll x = x0;
		ll y = y0;
		for(int j=0; j<i && max(x,y)<=INFLL/100; j++) {
			x = ax*x + bx;
			y = ay*y + by;
		}
		ll rem = t - dist(x,y,xs,ys);
		if(rem < 0) continue;
		ans = max(ans, max(down(rem,x,y,i), up(rem,x,y,i)));
	}
	cout << ans << nl;

	return 0;
}