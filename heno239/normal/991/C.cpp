#include<iostream>
#include<cstdio>
#include<string>
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
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
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
ll n;
bool eatmany(ll k){
	ll sum1 = 0; ll sum2 = 0;
	ll num = n;
	while (num > 0) {
		sum1 += min(num,k); num = max((ll)0,num-k); sum2 += num / (ll)10; num -= num / (ll)10;
	}
	if (sum1 >= sum2) {
		return true;
	}
	return false;
}
int main() {
	cin >> n;
		ll le = 0; ll ri = INF;
		while (ri - le > (ll)1) {
			ll mid = (ri + le) / (ll)2;
			if (eatmany(mid))ri = mid;
			else le = mid;
		}
	    cout << ri << endl;
	return 0;
}