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
const ll mod = 998244353;
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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
string s[6];
char t[3] = { 'R','G','B' };
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string ori; cin >> ori;
	rep(i, n) {
		int c = i % 3;
		s[0].push_back(t[c]);
		s[1].push_back(t[(c + 1) % 3]);
		s[2].push_back(t[(c + 2) % 3]);
		s[3].push_back(t[(3-c) % 3]);
		s[4].push_back(t[(4-c) % 3]);
		s[5].push_back(t[(5-c) % 3]);
	}
	int mi = mod;
	string ans;
	rep(i, 6) {
		int cnt = 0;
		rep(j, n) {
			if (s[i][j] != ori[j])cnt++;
		}
		if (cnt < mi) {
			mi = cnt; ans = s[i];
		}
	}
	cout << mi << endl;
	cout << ans << endl;
	//stop
	return 0;
}