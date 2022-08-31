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
int d[300];
int exi[1001];

vector<P> ans;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> d[i]; exi[d[i]] = 1;
	}
	int m = d[n - 1]+1;
	int l = 0, r = m - 1;
	int b = 0;
	int cnt = 0;
	while (l<r) {
		if (!exi[b]) {
			Rep1(i, l + 1, r) {
				ans.push_back({ l,i });
			}
			l++;
			cnt++;
		}
		else {
			r--;
			while (!exi[r - l +cnt]) {
				r--;
			}
			Rep1(i, l + 1, r) {
				ans.push_back({ l,i });
			}
			l++;
			cnt++;
		}
		b++;
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].first+1 << " " << ans[i].second + 1 << endl;
	}
	//stop
		return 0;
}