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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
P trans(char t) {
	if (t == 'R')return { 1,0 };
	else if (t == 'L')return { -1,0 };
	else if (t == 'U')return { 0,1 };
	else return { 0,-1 };
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string s; cin >> s;
	int x, y; cin >> x >> y;
	int le = -1; int ri = n;
	int ap = abs(x) + abs(y);
	if (ap > n||ap%2!=n%2) {
		cout << -1 << endl; return 0;
	}
	int nx = 0, ny = 0;
	while (le < n-1) {
		le++;
		P nex = trans(s[le]);
		nx += nex.first; ny += nex.second;
		int sum = abs(nx - x) + abs(ny - y);
		if (sum > n - 1 - le) {
			nx -= nex.first; ny -= nex.second; le--; break;
		}
	}
	//cout << le << endl;
	//cout << nx << " " << ny << endl;
	int out = ri-1-le;
	while (ri > 0 && ri>le+1) {
		ri--;
		P nex = trans(s[ri]);
		nx += nex.first; ny += nex.second;
		int sum = abs(nx - x) + abs(ny - y);
		//cout << sum << endl;
		//cout << le << " " << ri << endl;
		if (sum > ri - 1 - le) {
			while (le >= 0) {
				P nnex = trans(s[le]);
				nx -= nnex.first; ny -= nnex.second;
				int ssum = abs(nx - x) + abs(ny - y);
				if (ssum <= ri - le) {
					le--; break;
				}
				else le--;
			}
		}
		sum = abs(nx -x) + abs(ny - y);
		//cout << sum << " " << ri << endl;
		if (le<0 && sum>ri)break;
		out = min(out, ri - 1 - le);
		//cout << le << " " << ri << endl;
	}
	cout << out << endl;
	return 0;
}