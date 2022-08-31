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
typedef pair<int,int> P;
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
typedef pair<ll, ll> LP;
ll out[200001]; vector<ll> v;
map<ll, int> mp;
int main() {
	int n; cin >> n;
	rep(i, n) {
		ll r, l;
		scanf(" %lld", &l); scanf(" %lld", &r);
		r+=(ll)1;
		mp[l]++; mp[r]--;
		v.push_back(l); v.push_back(r);
	}
	sort(v.begin(), v.end());
	int len = v.size();
    int cnt = mp[v[0]];
	Rep(i, 1 ,len) {
		if (v[i] == v[i - 1])continue;
		out[cnt] += v[i] - v[i-1];
		cnt += mp[v[i]];
	}
	rep1(i, n) {
		printf("%lld", out[i]);
		if (i < n) {
			printf(" ");
		}
	}
	return 0;
}