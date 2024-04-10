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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
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
typedef pair<ll,P> PP;
int main() {
	int n; cin >> n;
	int k = sqrt(n + 0.1);
	int d = n / k; int r = n % k;
    vector<int> out;
	rep(i, d) {
		int s = (d -1- i)*k+r;
		rep(j, k) {
			out.push_back(s + j+1);
		}
	}
	rep(i, r) {
		out.push_back(i + 1);
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << out[i];
	}
	cout << endl;
	return 0;
}