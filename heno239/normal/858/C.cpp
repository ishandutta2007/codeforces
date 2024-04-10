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
int x[101];
bool b(char t) {
	if (t == 'a'||t=='e'||t=='u'||t=='i'||t=='o')return true;
	else return false;
}
bool space[3001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s; cin >> s;
	
	int c = 0;
	rep(i, s.length()) {
		if (!b(s[i])) {
			c++;
		}
		else c = 0;
		if (c >= 3) {
			bool g = true;
			Rep1(j, i - c + 1, i-1) {
				if (s[j] != s[j + 1]) {
					g = false;
				}
			}
			if (!g) {
				space[i] = true; c = 1;
			}
		}
	}
	rep(i, s.length()) {
		if (space[i]) {
			cout << " ";
		}
		cout << s[i];
	}
	cout << endl;
	return 0;
}