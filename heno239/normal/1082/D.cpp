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
int n;
int a[500];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	int sum = 0;
	rep(i, n) {
		cin >> a[i]; sum += a[i];
	}
	if (sum < 2 * n - 2) {
		cout << "NO" << endl;
	}
	else {
		vector<int> v;
		rep(i, n) {
			if (a[i] == 1) {
				v.push_back(i);
			}
		}
		if (v.size() <= 2) {
			cout << "YES " << n - 1 << endl;
			cout << n - 1 << endl;
			if (v.size() == 0) {
				rep1(i, n - 1) {
					cout << i << " " << i + 1 << endl;
				}
			}
			else if (v.size() == 1) {
				rep(i, n)if (v[0] != i)v.push_back(i);
				rep(i, n - 1) {
					cout << v[i]+1 << " " << v[i + 1]+1 << endl;
				}
			}
			else {
				rep(i, n)if (v[0] != i && v[1] != i)v.push_back(i);
				swap(v[1], v[n - 1]);
				rep(i, n - 1) {
					cout << v[i]+1 << " " << v[i + 1]+1 << endl;
				}
			}
		}
		else {
			vector<int> u;
			vector<P> add;
			u.push_back(v[0]);
			int k = 2;
			rep(i, n) {
				if (a[i] > 1) {
					u.push_back(i);
					Rep(j, 2, a[i]) {
						if (k == v.size())break;
						add.push_back({ v[k],i });
						k++;
					}
				}
			}
			u.push_back(v[1]);
			cout << "YES " << u.size() - 1 << endl;
			cout << n - 1 << endl;
			rep(i, u.size() - 1) {
				cout << u[i]+1 << " " << u[i + 1]+1 << endl;
			}
			rep(i, add.size()) {
				cout << add[i].first+1 << " " << add[i].second+1 << endl;
			}
		}
	}
	return 0;
}