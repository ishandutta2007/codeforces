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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = 998244353;
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
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int isp[100000] = {};
int main() {
	int n; scanf("%d", &n);
	ll g = 0;
	ll a, b;
	rep(i, n) {
		scanf(" %lld %lld", &a, &b);
		g = gcd(g, a*b);
	}
	Rep(i, 2, 100000) {
		if (isp[i])continue;
		if (g%i == 0)g = i;
		while (a%i == 0)a /= i;
		while (b%i == 0)b /= i;
		for (int j = 2 * i; j < 100000; j += i) {
			isp[j] = 1;
		}
	}
	if (g >= 100000) {
		if (a>=100000&&g%a == 0)g = a;
		if (b>=100000&&g%b == 0)g = b;
	}
	if (g > 1)printf("%lld\n", g);
	else printf("-1\n");
	return 0;
}