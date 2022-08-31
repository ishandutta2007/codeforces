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
const ll mod = (ll)(1e+9) + 7;
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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int a[1 << 18];
int inv[1 << 18];
int main() {
	int n; scanf("%d", &n);
	rep1(i, n) {
		scanf(" %d", &a[i]);
		inv[a[i]] = i;
	}
	int ri = 0;
	rep1(i, n) {
		int t; scanf( "%d", &t);
		int id = inv[t];
		int out;
		if (id < ri) {
			out = 0;
		}
		else {
			out = id - ri; ri = id;
		}
		if (i > 1) {
			printf(" ");
		}
		printf("%d", out);
	}
	printf("\n");
	return 0;
}