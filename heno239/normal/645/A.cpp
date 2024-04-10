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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<char> v, u;
	rep(i, 2) {
		string s; cin >> s;
		if (i == 0) {
			rep(j, 2) {
				if (s[j] != 'X')v.push_back(s[j]);
			}
		}
		else {
			per(j, 2){
				if (s[j] != 'X')v.push_back(s[j]);
		    }

		}
	}
	rep(i, 2) {
		string t; cin >> t;
		if (i == 0) {
			rep(j, 2) {
				if (t[j] != 'X')u.push_back(t[j]);
			}
		}
		else {
			per(j, 2) {
				if (t[j] != 'X')u.push_back(t[j]);
			}
		}
	}
	string ans = "NO";
	rep(j, 3) {
		if (u == v)ans = "YES";
		u.push_back(u[0]);
		u.erase(u.begin());
	}
	cout << ans << endl;
		return 0;
}