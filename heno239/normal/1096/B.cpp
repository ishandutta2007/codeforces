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
	int n; string s; cin >> n >> s;
	int le = 0;
	while (le + 1 < n&&s[le] == s[le + 1])le++;
	int ri = n - 1;
	while (ri - 1 >= 0 && s[ri] == s[ri - 1])ri--;
	if (s[le] == s[ri]) {
		cout << (ll)(le + 2)*(1 + n - ri) % mod << endl;
	}
	else {
		cout << le + 1 + n - ri + 1 << endl;
	}
	//stop
	return 0;
}