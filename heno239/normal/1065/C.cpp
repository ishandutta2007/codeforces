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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll h[1 << 18];
ll n, k;
vector<LP> v;
bool goodslice(ll x) {
	ll sum = 0;
	rep(i, (int)v.size()) {
		sum += max((ll)0, (v[i].first - x))*v[i].second;
	}
	if (sum <= k)return true;
	else return false;
}
bool update(ll x) {
	ll num = 0; int chk = v.end() - v.begin();
	rep(i, (int)v.size()) {
		if (v[i].first >= x) {
			num += v[i].second;
			chk = min(chk, i);
		}
	}
	v.erase(v.begin() + chk, v.end());
	v.push_back({ x,num });
	if (v.size() == 1)return true;
	else return false;
}
int main() {
	cin >> n >> k;
	rep(i, n) {
		//cin >> h[i];
		scanf(" %lld", &h[i]);
	}
	sort(h, h + n);
	rep(i, n) {
		ll cnt = 1;
		while (i + 1 < n&&h[i] == h[i + 1]) {
			i++; cnt++;
		}
		v.push_back({ h[i],cnt });
	}
	int cnt = 0;
	int len = v.size();
	while (true) {
		ll rest = k;
		per(j, len-1) {
			ll dif = v[j + 1].first - v[j].first;
			ll c = dif * v[j + 1].second;
			if (c < rest) {
				rest -= c;
				v[j].second += v[j + 1].second;
				len--;
				if (len == 1) {
					cnt++; break;
				}
			}
			else {
				cnt++; dif -= rest / v[j + 1].second;
				ll d = k / v[j + 1].second;
				cnt += dif / d;
				ll dis = d * (dif / d);
				v[j + 1].first = v[j].first + (dif - dis);
				if (v[j].first == v[j + 1].first) {
					len--; v[j].second += v[j+1].second;
				}
				break;
			}
		}
		if (len == 1)break;
	}
	cout << cnt << endl;
	return 0;
}