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
const ll mod = 998244353;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
bool isp[1 << 20];
vector<ll> p;
void init() {
	fill(isp + 2, isp + (1 << 20), true);
	Rep(i, 2, (1 << 20)) {
		if (!isp[i])continue;
		p.push_back(i);
		for (int j = 2 * i; j < (1 << 20); j += i) {
			isp[j] = false;
		}
	}
}
vector<ll> c;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	ll n, b; cin >> n >> b;
	vector<ll> v;
	ll ans = INF;
	rep(i, p.size()) {
		int cnt = 0;
		while (b%p[i]==0) {
			cnt++; b /= p[i];
		}
		if (cnt > 0) {
			ll cop = n;
			ll sum = 0;
			while (cop) {
				sum += cop / p[i]; cop /= p[i];
			}
			ans = min({ ans,sum / cnt });
		}
	}
	if (b>1) {
		ll cop = n;
		ll sum = 0;
		while (cop) {
			sum += cop / b; cop /= b;
		}
		ans = min({ ans,sum });
	}
	cout << ans << endl;
	//stop
	return 0;
}