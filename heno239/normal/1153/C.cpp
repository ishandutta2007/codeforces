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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
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
#define fr first
#define sc second

int n;
void solve() {
	cin >> n; string s; cin >> s;
	if (n % 2) {
		cout << ":(" << endl; return;
	}
	int a = 0, b = 0;
	rep(i, n) {
		if (s[i] == '(')a++;
		else if (s[i] == ')')b++;
	}
	if (a > n / 2 || b > n / 2) {
		cout << ":(" << endl; return;
	}
	if (s[0] != ')') {
		int sup = n / 2 - a;
		int cnt = 0;

		string t = s;
		int c = 0;
		bool f = true;
		rep(i, n) {
			if (s[i] == '(')c++;
			else if (s[i] == ')')c--;
			else {
				if (cnt < sup) {
					c++; t[i] = '('; cnt++;
				}
				else {
					t[i] = ')'; c--;
				}
			}
			if (i<n-1&&c <= 0) {
				f = false;
			}
		}
		if (f) {
			cout << t << endl; return;
		}
	}
	cout << ":(" << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}