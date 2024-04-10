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
const ll MOD = (1e+9) + 7;
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
int a[1000000];
int main() {
	int t;scanf("%d", &t);
	rep(i, t) {
		int n; scanf("%d", &n);
		vector<int> v;
		rep(j, n) {
			scanf("%d", &a[j]);
		}
		sort(a, a + n);
		bool f = false;
		rep(j, n) {
			int chk = j;
			while (j + 1 < n&&a[j + 1] == a[j])j++;
			int num = j - chk + 1;
			if (num >= 4) {
				printf("%d %d %d %d\n", a[chk], a[chk], a[chk], a[chk]); f = true; break;
			}
			else if (num >= 2)v.push_back(a[chk]);
		}
		if (f)continue;
		int len = v.size();
		ld mi = 100000;
		int out[4];
		rep(j, len - 1) {
			ld k = (ld)v[j + 1] / (ld)v[j];
			if (mi > k) {
				mi = k; out[0] = out[1] = v[j]; out[2] = out[3] = v[j + 1];
			}
		}
		printf("%d %d %d %d\n", out[0], out[1], out[2], out[3]);
	}
	return 0;
}