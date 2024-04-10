#include<iostream>
#include<string>
#include<stdio.h>
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
const ll MOD = (1e+9)+7;
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
typedef pair<ll,P> PP;
int sum[1 << 12][101] = {};
int cnt[1 << 12] = {};
int n;
int fix(char x[13]) {
	int res = 0;
	rep(i, n) {
		if (x[i] == '1') {
			res += (1<<i);
		}
	}
	return res;
}
int main() {
	int q, m;
	scanf("%d %d %d", &n, &m, &q);
	int a[12];
	rep(i, n) {
	    int aa;
		scanf("%d", &aa);
		a[i]=aa;
	}
	rep(i, m) {
		char t[13]; scanf(" %s", t);
		int s = fix(t);
		cnt[s]++;
	}
	rep(i, 1 << n) {
		rep(j, 1 << n) {
			int csum = 0;
			rep(k, n) {
				int x1 = i & (1 << k);
				int x2 = j & (1 << k);
				if (x1 == x2)csum += a[k];
			}
			if (csum > 100)continue;
			sum[i][csum] += cnt[j];
		}
	}
	rep(i, 1 << n) {
		Rep(j,1, 101) {
			sum[i][j] += sum[i][j - 1];
		}
	}
	rep(i, q) {
		char t[13]; scanf("%s", t); int k; scanf("%d", &k);
		int s = fix(t);
		printf("%d\n", sum[s][k]);
	}
	return 0;
}