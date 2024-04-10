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
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int n; int a[500000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)cin >> a[i];
	int out = 0;
	rep1(i, n-1) {
		if (a[i] != a[i - 1]) {
			int le = i - 1;
			int ri = i;
			while (ri + 1 < n&&a[ri + 1] != a[ri])ri++;
			int num = (ri - le) / 2;
			out = max(out, num);
			if (a[le] == a[ri]) {
				Rep1(j, le + 1, ri - 1) {
					a[j] = a[le];
				}
			}
			else {
				Rep1(j, le + 1, ri - 1) {
					if (j <= le + num) {
						a[j] = a[le];
					}
					else {
						a[j] = a[ri];
					}
				}
			}
			i = ri;
			//cout << le << " " << ri << endl;
		}
	}
	cout << out << endl;
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << a[i];
	}
	return 0;
}