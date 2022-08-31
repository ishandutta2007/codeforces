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
typedef long double ld;
const ld INF = (ld)10000000000000;
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

vector<int> zalgo(string s) {
	int n = s.length();
	vector<int> ret(n);
	ret[0] = n;
	int i = 1, j = 0;
	while (i < n) {
		while (i + j < n && s[j] == s[i + j])
			++j;
		ret[i] = j;
		if (j == 0) {
			++i;
			continue;
		}
		int k = 1;
		while (i + k < n && k + ret[k] < j) {
			ret[i + k] = ret[k];
			++k;
		}
		i += k;
		j -= k;
	}
	return ret;
}
string s, t;
int c[2], d[2];
int e[2];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s >> t;
	int n = s.length(), m = t.length();
	rep(i, n) {
		c[s[i] - '0']++;
	}
	rep(i, m) {
		d[t[i] - '0']++;
	}
	vector<int> v = zalgo(t);
	int id = m;
	rep1(i, m - 1) {
		if (v[i] == m - i) {
			id = i; break;
		}
	}
	int len = m - id;
	Rep(i, len, m) {
		e[t[i] - '0']++;
	}
	string ans;
	if (c[0] >= d[0] && c[1] >= d[1]) {
		rep(i, m)ans.push_back(t[i]);
		c[0] -= d[0]; c[1] -= d[1];
		while (c[0] >= e[0] && c[1] >= e[1]) {
			c[0] -= e[0]; c[1] -= e[1];
			Rep(i, len , m) {
				ans.push_back(t[i]);
			}
		}
	}
	rep(i, c[0])ans.push_back('0');
	rep(i, c[1])ans.push_back('1');
	cout << ans << endl;
	//stop
		return 0;
}