#include<iostream>
#include<cstdio>
#include<string>
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
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
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
int main() {
	int n; cin >> n;
	int a[200];
	rep(i, 2*n) {
		cin >> a[i];
	}
	int cnt = 0;
	rep(i, n) {
		int now = i * 2;
		int memo = a[now];
		int chk;
		Rep(j, now + 1, 2 * n) {
			if (memo == a[j]) {
				chk = j; break;
			}
		}
		for (int j = chk; j > now + 1; j--) {
			int x = a[j]; a[j] = a[j - 1]; a[j - 1] = x; cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}