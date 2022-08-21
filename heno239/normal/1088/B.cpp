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
const ll mod = 1000000009;
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
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	priority_queue<ll,vector<ll>,greater<ll>> q;
	rep(i, n) {
		ll a; cin >> a; q.push(a);
	}
	ll sum = 0;
	rep(i, k) {
			bool ansed = false;
			while (!q.empty()) {
				ll x = q.top(); q.pop();
				if (x - sum > 0) {
					cout << x - sum << endl; sum = x; ansed = true; break;
				}
			}
			if (!ansed)cout << 0 << endl;
	}
	return 0;
}