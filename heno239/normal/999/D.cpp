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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
int main() {
	ll a[200000]; int n; ll m; cin >> n >> m;
	ll b[200000];
	fill(b, b + m, -n / m);
	rep(i, n) {
		scanf(" %lld", &a[i]);
	}
	rep(i, n) {
		b[a[i] % m]++;
	}
	set<int>st;
	vector<int> v;
	rep(i, m) {
		if (b[i] < 0) {
			st.insert(i); st.insert(i + (int)m);
		}
	}
	ll cnt = 0;
	rep(i, n) {
		int r = (int)(a[i] % m);
		if (b[r] > 0) {
			b[r]--;
			st.insert(r);
			auto itr = st.find(r); itr++;
			int nex = *itr;
			ll dif = nex - r;
			cnt += dif;
			b[nex%(int)m]++; a[i] += dif;
			if (b[nex%(int)m] == 0) {
				st.erase(nex); st.erase((nex + (int)m) % (2 * (int)m));
			}
			st.erase(r);
		}
	}
	cout << cnt << endl;
	rep(i, n) {
		printf("%lld", a[i]);
		if (i<n - 1)printf(" ");
	}
	printf("\n");
	return 0;
}