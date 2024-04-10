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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);



void solve() {
	int a, b; cin >> a >> b;
	string s; cin >> s;
	int n = s.length();
	vector<int> memo;
	int num = 0;
	rep(i, n) {
		if (s[i] == '.') {
			int le = i;
			while (i + 1 < n&&s[i + 1] == '.')i++;
			int len = i - le + 1;
			if (len >= 2 * b) {
				memo.push_back(len);
			}
			else if (a <= len) {
				num++;
			}
			else if (b <= len) {
				cout << "No" << endl; return;
			}
		}
	}
	if (memo.size() >= 2) {
		cout << "No" << endl; return;
	}
	if (memo.size() == 0) {
		if (num % 2 == 0) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
		return;
	}
	else {
		int d = memo[0];
		if (d >= a + 2 * (2 * b)) {
			cout << "No" << endl; return;
		}
		bool f = false;
		rep(i, d - a + 1) {
			int le = i; int ri = d - le - a;
			if (le < b) {
				if (ri < b) {
					if (num % 2 == 0) {
						cout << "Yes" << endl; return;
					}
				}
				else if (ri < a) {
					//
				}
				else if (ri >= 2*b) {
					//
				}
				else {
					if (num % 2) {
						cout << "Yes" << endl; return;
					}
				}
			}
			else if (le < a) {
				//
			}
			else if (le >= 2 * b) {
				//
			}
			else {
				if (ri < b) {
					if (num % 2) {
						cout << "Yes" << endl; return;
					}
				}
				else if (ri < a) {
					//
				}
				else if (ri >= 2 * b) {
					//
				}
				else {
					if (num % 2 == 0) {
						cout << "Yes" << endl; return;
					}
				}
			}
		}
		cout << "No" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//init();
	int q; cin >> q;
	rep(aa, q) {
		solve();
	}
	//stop
		return 0;
}