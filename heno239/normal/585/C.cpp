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
	ll a, b; cin >> a >> b;
	vector<ll> v;
	int s = 0;
	while (a > 1 || b > 1) {
		if (a > b) {
			if (b > 1) {
				v.push_back(a / b);
				a = a % b;
			}
			else {
				v.push_back(a - b);
				a = 1; s = 1;
			}
		}
		else {
			if (a > 1) {
				v.push_back(b / a);
				b = b % a;
			}
			else {
				v.push_back(b - a);
				b = 1; s = 0;
			}
		}
		if (a == 0 || b == 0) {
			cout << "Impossible" << endl; return 0;
		}
	}
	s ^= (v.size() % 2);
	rep(i, v.size()) {
		cout << v[i] << (char)('A' + s);
		s ^= 1;
	}
	cout << endl;
		return 0;
}