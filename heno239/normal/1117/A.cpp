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
int n;
int a[1 << 17];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	int ma = -1;
	rep(i, n) {
		cin >> a[i]; ma = max(ma, a[i]);
	}
	int ans = 1;
	rep(i, n) {
		int le = i;
		while (i + 1 < n&&a[i + 1] == a[i])i++;
		if(ma==a[i])ans = max(ans, i - le + 1);
	}
	cout << ans << endl;
	//stop
	return 0;
}