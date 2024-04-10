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
int cnt[1001];
int ans[20][20];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n*n) {
		int a; cin >> a; cnt[a]++;
	}
	if (n % 2 == 0) {
		vector<int> v;
		bool valid = true;
		rep(i, 1001) {
			if (cnt[i] % 4 != 0) {
				valid = false;
			}
			else {
				rep(j, cnt[i] / 4)v.push_back(i);
			}
		}
		if (!valid)cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			rep(i, n / 2) {
				rep(j, n / 2) {
					int num = i * (n / 2) + j;
					ans[i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][j] = ans[n - 1 - i][n - 1 - j] = v[num];
				}
			}
			rep(i, n) {
				rep(j, n) {
					if (j > 0)cout << " ";
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
	}
	else {
		int k = 2 * n - 2;
		vector<int> v,u; int chk = -1;
		bool valid = true;
		rep(i, 1001) {
			if (cnt[i] % 4 == 1) {
				if (chk >= 0)valid = false;
				else chk = i;
				rep(j, cnt[i] / 4)v.push_back(i);
			}
			else if (cnt[i] % 4 == 0) {
				rep(j, cnt[i] / 4)v.push_back(i);
			}
			else if (cnt[i] % 4 == 2) {
				u.push_back(i);
				rep(j, cnt[i] / 4)v.push_back(i);
			}
			else {
				if (chk >= 0)valid = false;
				else {
					chk = i; u.push_back(i);
					rep(j, cnt[i] / 4)v.push_back(i);
				}
			}
		}
		if (chk < 0)valid = false;
		if (v.size() < (n / 2)*(n / 2))valid = false;
		if (!valid)cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			rep(i, n / 2) {
				rep(j, n / 2) {
					int num = i * (n / 2) + j;
					ans[i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][j] = ans[n - 1 - i][n - 1 - j] = v[num];
				}
			}
			Rep(j, (n / 2)*(n / 2), v.size()) {
				rep(aaa, 2)u.push_back(v[j]);
			}
			int m = n / 2; int cur = 0;
			rep(i, (n - 1) / 2) {
				ans[m][i] = ans[m][n-1-i]=u[cur]; cur++;
			}
			rep(i, (n - 1) / 2) {
				ans[i][m] = ans[n - 1 - i][m] = u[cur]; cur++;
			}
			ans[m][m] = chk;
			rep(i, n) {
				rep(j, n) {
					if (j > 0)cout << " ";
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
	}
	//stop
	return 0;
}