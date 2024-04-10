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
typedef unsigned long long ll;
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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
string out1, out2;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(),greater<char>());
	int n = s.length();
	int ri1 = (n - 1) / 2;
	int ri2 = (n - 2) / 2;
	int n1 = 0; int n2 = 0;
	int n3 = 0; int n4 = 0;
	rep(i, n) {
		if (i % 2 == 0) {
			if (s[n1] < t[n2]) {
				out1.push_back(s[n1]);
				n1++;
			}
			else {
				out2.push_back(s[ri1-n3]);
				n3++;
			}
		}
		else {
			if (s[n1] < t[n2]) {
				out1.push_back(t[n2]);
				n2++;
			}
			else {
				out2.push_back(t[ri2-n4]);
				n4++;
			}
		}
	}
	reverse(out2.begin(), out2.end());
	out1 += out2;
	cout << out1 << endl;
		return 0;
}