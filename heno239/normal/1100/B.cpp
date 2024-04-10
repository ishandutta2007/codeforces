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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int cnt[1 << 17];
int m, n;
int c = 0;
string ans;
int a[1 << 17];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> m >> n;
	rep(i, n) {
		cin >> a[i];
	}
	ans.resize(n,'0');
	rep(i, n) {
		if (cnt[a[i]] == 0) {
			c++; cnt[a[i]] = 1;
		}
		else {
			cnt[a[i]]++;
		}
		if (c == m) {
			ans[i] = '1';
			rep1(i, m) {
				cnt[i]--;
				if (cnt[i] == 0)c--;
			}
		}
	}
	cout << ans << endl;
	//stop
	return 0;
}