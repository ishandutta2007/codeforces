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
const ll INF = mod*mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

int a[500][500], b[500][500];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> a[i][j];
		}
	}
	rep(i, n) {
		rep(j, m) {
			cin >> b[i][j];
		}
	}
	rep(i, n - 1) {
		rep(j, m - 1) {
			if (a[i][j] != b[i][j]) {
				rep(k, 2) {
					rep(l, 2) {
						a[i + k][j + l] ^= 1;
					}
				}
			}
		}
	}
	rep(i, n) {
		rep(j, m) {
			if (a[i][j] != b[i][j]) {
				cout << "No" << endl; return;
			}
		}
	}
	cout << "Yes" << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}