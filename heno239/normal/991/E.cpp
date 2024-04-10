#include<iostream>
#include<cstdio>
#include<string>
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
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
ll sum(string s) {
	ll per[19]; 
	per[0] = 1;
	for (ll i = 1; i <= 18; i++) {
		per[i] = per[i - 1] * i;
	}
	ll res = 0;
	map<string, int>used;
	queue<string> q;
	q.push(s);
	while (!q.empty()) {
		string now = q.front(); q.pop();
		int num[10] = {};
		int len = now.length();
		rep(i, len) {
			num[now[i] - '0']++;
		}
		ll cnt = per[len];
		rep(i, 10) {
			cnt /= per[num[i]];
		}
		res += cnt;
		if (now[0] == '0') {
			cnt = per[len - 1];
			num[0]--;
			rep(i, 10) {
				cnt /= per[num[i]];
			}
			res -= cnt;
		}
		rep(i, len - 1) {
			if (now[i] == now[i + 1]) {
				string u = now;
				u.erase(u.begin() + i);
				if (used[u] != 1) {
					used[u] = 1; q.push(u);
				}
			}
		}
	}
	return res;
}
int main() {
	string s; cin >> s;
	sort(s.begin(), s.end());
	if (s.length() == 19) {
		cout << 18 << endl; return 0;
	}
	cout << sum(s) << endl;
	return 0;
}