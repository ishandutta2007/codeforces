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
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	P a[3];
	rep(i, 3) {
		int x, y; cin >> x >> y;
		a[i] = { x,y };
	}
	sort(a, a + 3);
	vector<P> ans;
	Rep(i, a[0].first, a[1].first) {
		ans.push_back({ i,a[0].second });
	}
	int le = min(a[0].second, a[1].second);
	int ri = max(a[0].second, a[1].second);
	Rep1(i, le, ri) {
		ans.push_back({ a[1].first,i });
	}
	int c = a[2].second;
	Rep1(i, a[1].first + 1, a[2].first) {
		ans.push_back({ i,c });
	}
	if (c > ri) {
		Rep1(i, ri + 1, c) {
			ans.push_back({ a[1].first,i });
		}
	}
	else if (c < le) {
		Rep1(i, c, le - 1) {
			ans.push_back({ a[1].first,i });
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}