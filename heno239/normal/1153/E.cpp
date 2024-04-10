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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

int t;
int x[2], y[2];
void solve() {
	int n; cin >> n;
	rep1(i, n - 1) {
		cout << "? 1 1 " << n << " " << i << endl;
		cin >> t;
		if (t % 2) {
			//left
			int le = 0, ri = i + 1;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				cout << "? 1 1 " << n << " " << mid << endl;
				cin >> t;
				if (t % 2) {
					ri = mid;
				}
				else {
					le = mid;
				}
			}
			y[0] = ri;
			le = 0, ri = n + 1;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				cout << "? 1 " << y[0] << " " << mid << " " << y[0] << endl;
				cin >> t;
				if (t % 2) {
					ri = mid;
				}
				else {
					le = mid;
				}
			}
			x[0] = ri;
			//right
			le = i, ri = n + 1;
			while (ri - le > 1) {
				int mid = (le + ri) / 2;
				cout << "? 1 " << mid << " " << n << " " << n << endl;
				cin >> t;
				if (t % 2) {
					le = mid;
				}
				else {
					ri = mid;
				}
			}
			y[1] = le;
			le = 0, ri = n + 1;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				cout << "? 1 " << y[1] << " " << mid << " " << y[1] << endl;
				cin >> t;
				if (t % 2) {
					ri = mid;
				}
				else {
					le = mid;
				}
			}
			x[1] = ri;
			cout << "! " << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl;
			cin >> t;
			return;
		}
	}
	rep1(i, n - 1) {
		cout << "? 1 1 " << i << " " << n << endl;
		cin >> t;
		if (t % 2) {
			//left
			int le = 0, ri = i;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				cout << "? 1 1 " << mid << " " << n << endl;
				cin >> t;
				if (t % 2) {
					ri = mid;
				}
				else {
					le = mid;
				}
			}
			x[0] = ri;
			le = 0, ri = n;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				cout << "? " << x[0] << " 1 " << x[0] << " " << mid << endl;
				cin >> t;
				if (t % 2) {
					ri = mid;
				}
				else {
					le = mid;
				}
			}
			y[0] = ri;
			//right
			le = i+1, ri = n + 1;
			while (ri - le > 1) {
				int mid = (le + ri) / 2;
				cout << "? " << mid << " 1 " << n << " " << n << endl;
				cin >> t;
				if (t % 2) {
					le = mid;
				}
				else {
					ri = mid;
				}
			}
			x[1] = le; 
			y[1] = y[0];
			/*le = 0, ri = n + 1;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				cout << "? " << x[1] << " 1 " << x[1] << " " << mid << endl;
				cin >> t;
				if (t % 2) {
					ri = mid;
				}
				else {
					le = mid;
				}
			}
			y[1] = ri;*/
			cout << "! " << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl;
			cin >> t;
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}