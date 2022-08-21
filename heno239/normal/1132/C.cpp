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
const ll INF = mod * mod;
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

int l[5000], r[5000];
int c[5001];
void solve() {
	int n, q; cin >> n >> q;
	rep(i, q) {
		cin >> l[i] >> r[i]; l[i]--; r[i]--;
		c[l[i]]++; c[r[i] + 1]--;
	}
	rep(i, n) {
		c[i + 1] += c[i];
	}
	int out = 0;
	rep(i, q-1) {
		int ans = n;
		vector<int> v;
		rep(j, n) {
			int t = c[j];
			if (l[i] <= j && j <= r[i]) {
				t--;
			}
			if (t == 0)ans--;
			else if (t == 1)v.push_back(j);
		}
		int mi = mod;
		Rep(j, i + 1, q) {
			int num = upper_bound(v.begin(), v.end(), r[j]) - lower_bound(v.begin(), v.end(), l[j]);
			//cout << num << endl;
			mi = min(mi, num);
		}
		out = max(out, ans - mi);
	}
	cout << out << endl;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}