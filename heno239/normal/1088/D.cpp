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
const ll mod = 1000000009;
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
int q(ll x,ll y) {
	cout << "? " << x << " "<<y << endl;
	int res; cin >> res; return res;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a1 = 0,a2=0;
	int z = q(0, 0);
	per(i, 30) {
		ll k = (ll)1 << i;
		if (z >= 0) {
			int u = q(a1^k, a2^k);
			if (u >= 0) {
				u = q(a1^k, a2);
				if (u == -1) {
					a1 ^= k; a2 ^= k;
				}
			}
			else {
				a1 ^= k; z = q(a1, a2);
			}
		}
		else {
			int u = q(a1^k, a2^k);
			if (u <= 0) {
				u = q(a1^k, a2);
				if (u == -1) {
					a1 ^= k; a2 ^= k;
				}
			}
			else {
				a2 ^= k; z = q(a1, a2);
			}
		}
	}
	cout << "! " << a1 << " " << a2 << endl;
	return 0;
}