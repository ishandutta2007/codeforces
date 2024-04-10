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
const ll mod = 998244353;
typedef long double ld;
const ll INF = mod * mod;
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

int a[500][500];
void solve() {
	int n, m; cin >> n >> m;
	int s = 0; vector<int> ans;
	rep(i, n) {
		rep(j, m) {
			cin >> a[i][j];
		}
		s ^= a[i][0]; ans.push_back(1);
	}
	if (s == 0) {
		rep(i, n) {
			rep1(j, m - 1) {
				if (a[i][0] != a[i][j]) {
					ans[i] = j + 1;
					cout << "TAK" << endl;
					rep(k, ans.size()) {
						if (k > 0)cout << " ";
						cout << ans[k];
					}
					cout << endl;
					return;
				}
			}
		}
		cout << "NIE" << endl;
	}
	else {
		cout << "TAK" << endl;
		rep(i, ans.size()) {
			if (i > 0)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}