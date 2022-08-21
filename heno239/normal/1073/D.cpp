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
ll a[1 << 18];

int nn; LP dat[1 << 20];
LP plu(LP x, LP y) {
	return { x.first + y.first,x.second + y.second };
}
void init(int n) {
	nn = 1;
	while (nn < n)nn *= 2;
}
void update(int k, LP a) {
	k += nn - 1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = plu(dat[k * 2 + 1] , dat[k * 2 + 2]);
	}
}
LP query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l)return { 0,0 };
	if (a <= l && r <= b)return dat[k];
	else {
		LP vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		LP vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return plu(vl , vr);
	}
}
int main() {
	int n; cin >> n; init(2 * n);
	ll t; cin >> t;
	ll sum = 0;
	rep(i, n) {
		scanf(" %lld", &a[i]);
		//cin >> a[i];
		sum += a[i];
	}
	if (n == 1) {
		cout << t / a[0] << endl; return 0;
	}
	rep(i, 2 * n) {
		update(i,{ a[i%n], 1 });
	}
	int id = 0; ll out = 0; ll num = n;
	while (t) {
		if (t >= sum) {
			out += (t / sum)*num;
			t %= sum;
		}
		else {
			int le = id; int ri = id+n;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				ll csum = query(id, mid, 0, 0, nn).first;
				//cout << csum << endl;
				if (csum <= t) {
					le = mid;
				}
				else ri = mid;
			}
			LP aa = query(id, le, 0, 0, nn);
			out += aa.second;
			t -= aa.first;
			num--;
			sum -= a[le%n];
			update(le%n, { 0,0 });
			update(le%n + n, { 0,0 });
			id = le % n;
			//cout << le << endl;
		}
		if (num == 0)break;
		//cout << out << " "<<t<<endl;
	}
	cout << out << endl;
	return 0;
}