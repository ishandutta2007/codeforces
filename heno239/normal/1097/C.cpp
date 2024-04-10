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
const ld eps = 1e-3;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n;
const int mn = 1 << 20;
int mi[mn]; int val[mn];
int cnt[mn][2];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		string s; cin >> s;
		int c = 0; int len = s.length();
		rep(j, len) {
			if (s[j] == '(')c++;
			else c--;
			mi[i] = min(mi[i], c);
		}
		val[i] = c;
	}
	int ans = 0;
	rep(i, n) {
		if (val[i] > 0) {
			if (mi[i] < 0)continue;
			cnt[val[i]][0]++;
		}
		else if (val[i] < 0) {
			if (mi[i] < val[i])continue;
			cnt[-val[i]][1]++;
		}
		else {
			if (mi[i] >= 0)ans++;
		}
	}
	ans /= 2;
	rep1(i, mn-1) {
		ans += min(cnt[i][0], cnt[i][1]);
	}
	cout << ans << endl;
	//stop
	return 0;
}