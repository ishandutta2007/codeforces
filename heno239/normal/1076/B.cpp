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
const ll mod = (1e+9) + 7;
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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int isp[1 << 17];
vector<ll> p;
void init() {
	fill(isp + 2, isp + (1 << 17), true);
	Rep(i, 2, 1 << 17) {
		if (!isp[i])continue;
		p.push_back(i);
		for (int j = 2 * i; j < (1 << 17); j += i) {
			isp[j] = false;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n; cin >> n; init();
	int cnt = 0;
	ll chk = n;
	rep(i, (int)p.size()) {
		ll a = p[i];
		if (n%a == 0) {
			chk = a; break;
		}
	}
	cout << 1+(n - chk) / 2 << endl;
	return 0;
}