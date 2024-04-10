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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
string s;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k, n; cin >> n >> k;
	int le = 1; int ri = n;
	while (ri - le > 1) {
		int mid = (le + ri - 2) / 2;
		cout << 1 << " " << mid << " " << mid+1 << endl;
		cin >> s;
		if (s == "TAK") {
			ri = mid;
		}
		else {
			le = mid + 1;
		}
	}
	cout << 1 << " " << le << " " << ri << endl;
	cin >> s;
	int ans;
	if (s == "TAK") {
		ans = le;
	}
	else {
		ans = ri;
	}
	bool ansed = false;
	le = 1; ri = ans - 1;
	if (ans >= 3) {
		while (ri - le > 1) {
			int mid = (le + ri - 2) / 2;
			cout << 1 << " " << mid << " " << mid + 1 << endl;
			cin >> s;
			if (s == "TAK") {
				ri = mid;
			}
			else {
				le = mid + 1;
			}
		}
		cout << 1 << " " << le << " " << ri << endl;
		cin >> s;
		if (s == "TAK") {
			cout << 2 << " " << le << " " << ans << endl;
			ansed = true;
		}
		else {
			cout << 1 << " " << ans-1 << " " << ans << endl;
			cin >> s;
			if (s == "TAK") {
				cout << 2 << " " << ans - 1 << " " << ans << endl;
				ansed = true;
			}
		}
	}
	if (!ansed) {
		le = ans + 1; ri = n;
		while (ri - le > 1) {
			int mid = (le + ri) / 2;
			cout << 1 << " " << mid << " " << mid + 1 << endl;
			cin >> s;
			if (s == "TAK") {
				ri = mid;
			}
			else {
				le = mid + 1;
			}
		}
		cout << 1 << " " << le << " " << ri << endl;
		cin >> s;
		if (s == "TAK") {
			cout << 2 << " " << ans << " " << le << endl;
		}
		else {
			cout << 2 << " " << ans << " " << ri << endl;
		}
	}
	return 0;
}