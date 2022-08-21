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
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
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
typedef vector<int> vec;
typedef vector<string> svec;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	int ans = mod;
	int chk = 0;
	rep(i, n) {
		if (b[i] == 1) {
			int le = i;
			bool f = true;
			Rep(j, i + 1, n) {
				if (b[j] != j - i + 1)f = false;
			}
			if (f) {
				queue<int> q;
				vector<bool> exi(n + 1, false);
				rep(i, n) {
					exi[a[i]] = true;
				}
				rep(j, i) {
					q.push(b[j]);
				}
				int cur = n - i + 1;
				rep(j, i) {
					if (!exi[cur]) {
						f = false; break;
					}
					else {
						cur++;
						if (!q.empty()) {
							exi[q.front()] = true;
							q.pop();
						}
					}
				}
				if (f) {
					cout << i << endl; return;
				}
			}
			break;
		}
	}
	int ma = 0;
	rep(i, n) {
		if (b[i] > 0) {
			ma = max(ma, i+1 - (b[i] - 1));
		}
	}
	cout << ma + n << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n,n)solve();
	solve();
	//stop
	return 0;
}