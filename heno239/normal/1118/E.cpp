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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int a[1 << 18], b[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	ll z = (ll)k*(k - 1);
	if (n > z)cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int cnt = 0;
		rep1(i, k) {
			Rep1(j, i + 1, k) {
				if (cnt >= n)break;
				a[cnt] = i, b[cnt] = j;
				cnt++;
				a[cnt] = j, b[cnt] = i;
				cnt++;
			}
			if (cnt >= n)break;
		}
		rep(i, n) {
			cout << a[i] << " " << b[i] << endl;
		}
	}
	//stop
	return 0;
}