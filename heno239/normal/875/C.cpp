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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<int> v[1 << 17];
int pri[1 << 17];
vector<int> G[1 << 17];
bool baku[1 << 17];
int main() {
	queue<int> q;
	int n, m; cin >> n >> m;
	rep(i, n) {
		int t; scanf(" %d", &t);
		rep(j, t) {
			int a; scanf(" %d", &a);
			v[i].push_back(a);
		}
	}
	bool exi = true;
	rep(i, n - 1) {
		int l1 = v[i].size();
		int l2 = v[i + 1].size();
		bool f = true;
		rep(j, min(l1, l2)) {
			if (v[i][j] != v[i + 1][j])f = false;
		}
		if (f) {
			if (l1 > l2)exi = false;
		}
		else {
			rep(j, min(l1, l2)) {
				int c1 = v[i][j];
				int c2 = v[i + 1][j];
				if (c1 != c2) {
					if (c1 < c2) {
						q.push(c2);
						G[c2].push_back(c1);
						baku[c2] = true;
					}
					else {
						if (pri[c1] == -1 || pri[c2] == 1) {
							exi = false;
						}
						pri[c1] = 1; pri[c2] = -1;
					}
					break;
				}
			}
		}
	}
	int len = q.size();
	rep(i, len) {
		int x = q.front(); q.pop();
		if (pri[x] == 1) {
			q.push(x); baku[x] = false;
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		rep(i, (int)G[x].size()) {
			int y = G[x][i];
			if (pri[y] == -1)exi = false;
			pri[y] = 1;
			if (baku[y]) {
				baku[y] = false; q.push(y);
			}
		}
	}
	if (exi) {
		cout << "Yes" << endl;
		int cnt = 0;
		rep1(i, m) {
			if (pri[i] == 1)cnt++;
		}
		cout << cnt << endl;
		bool bla = false;
		rep1(i, m) {
			if (pri[i] == 1) {
				if (bla)cout << " ";
				else bla = true;
				cout << i;
			}
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}