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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; cin >> s; int n = s.length();
	int le=n, ri=-1;
	rep(i, n) {
		if (s[i] == '[')le = min(le, i);
		else if (s[i] == ']')ri = max(ri, i);
	}
	if (le > ri) {
		cout << -1 << endl;
	}
	else {
		int l = ri, r = le;
		Rep1(i, le + 1, ri-1) {
			if (s[i] == ':') {
				l = min(l, i);
				r = max(r, i);
			}
		}
		if (l >= r) {
			cout << -1 << endl;
		}
		else {
			int cnt = 0;
			Rep1(i, l + 1, r - 1) {
				if (s[i] == '|')cnt++;
			}
			cout << cnt+4 << endl;
		}
	}
	//stop
	return 0;
}