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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9) + 7;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int trans(string x) {
	int len = x.length();
	int now = 1; int res = 0;
	per(i, len) {
		res += now * (int)(x[i] - 'A' + 1);
		now *= 26;
	}
	return res;
}
string inver(int x) {
	int now = 0;
	string res;
	while (x) {
		if (x % 26 > 0) {
			res.push_back('A' + x % 26 - 1);
		}
		else {
			x -= 26; res.push_back('Z');
		}
		x /= 26;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n; cin >> n;
	rep(i, n) {
		string s; cin >> s; int len = s.length();
		vector<int> v; int chk;
		rep(j, len) {
			if ('0' <= s[j] && s[j] <= '9') {
				chk = j;
				string u;
				while (j<len&&'0' <= s[j] && s[j] <= '9') {
					u += s[j]; j++;
				}
				v.push_back(stoi(u));
			}
		}
		if (v.size() == 1) {
			string t = s.substr(0, chk);
			int r = trans(t);
			cout << "R" << v[0] << "C" << r << endl;
		}
		else {
			string t = inver(v[1]);
			cout << t << v[0] << endl;
		}
	}
	return 0;
}