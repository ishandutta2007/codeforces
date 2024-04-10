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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll bit[1 << 19]; int n;
void add(int a, ll w) {
	for (int i = a; i <= n + 1; i += i & -i)bit[i] += w;
}
ll sum(int a) {
	ll ret = 0;
	for (int i = a; i > 0; i -= i & -i)ret += bit[i];
	return ret;
}
int main() {
	cin >> n;
	int ri = n;
	cout << 1;
	rep1(i, n) {
		int a; scanf(" %d", &a);
		add(a, 1);
		while (ri>0&&i - sum(ri - 1) == n-ri+1) {
			ri--;
		}
		printf(" "); printf("%d", 1 + sum(ri - 1));
	}
	cout << endl;
	return 0;
}