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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int out = 2*n;
	vector<int> v;
	rep(i, n) {
		if (s[i] == '0')v.push_back(i);
	}
	int m = v.size();
	rep(i, m - k) {
		int le = v[i]; int ri = v[i + k];
		int id = lower_bound(v.begin(), v.end(), (le + ri) / 2) - v.begin();
		int c = max(ri - v[id], v[id] - le);
		id--;
		if (id >= 0) {
			c = min(max(ri - v[id], v[id] - le),c);
		}
		out = min(out, c);
	}
	cout << out << endl;
		return 0;
}