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
int n;
const int MAX_N = (1 << 18);
int nn, dat[3][2 * MAX_N - 1];
void init(int n_) {
	nn = 1;
	while (nn < n_)nn *= 2;
}
void update(int id,int k, int a) {
	k += nn - 1;
	dat[id][k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[id][k] = dat[id][k * 2 + 1]+dat[id][k * 2 + 2];
	}
}
int query(int id, int a, int b, int k, int l, int r) {
	if (r <= a || b <= l)return 0;
	if (a <= l && r <= b)return dat[id][k];
	else {
		int vl = query(id, a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(id, a, b, k * 2 + 2, (l + r) / 2, r);
		return vl + vr;
	}
}
int exile(int id) {
	if (query(id, 0, n, 0, 0, nn)==0)return n;
	int k = 0;
	while (k < nn - 1) {
		int vl = dat[id][k * 2 + 1], vr = dat[id][k * 2 + 2];
		if (vl)k = k * 2 + 1;
		else k = k * 2 + 2;
	}
	return k - (nn - 1);
}
int exiri(int id) {
	if (query(id, 0, n, 0, 0, nn) == 0)return -1;
	int k = 0;
	while (k < nn - 1) {
		int vl = dat[id][k * 2 + 1], vr = dat[id][k * 2 + 2];
		if (vr)k = k * 2 + 2;
		else k = k * 2 + 1;
	}
	return k - (nn - 1);
}
int trans(char t) {
	if (t == 'R')return 0;
	else if (t == 'S')return 1;
	else return 2;
}
int le[3][2], ri[3][2];
int ans() {
	int res = 0;
	rep(i, 3) {
		le[i][0] = exile((i + 1) % 3); ri[i][0] = exiri((i + 1) % 3);
		le[i][1] = exile((i + 2) % 3); ri[i][1] = exiri((i + 2) % 3);
		if (le[i][0] <= le[i][1]) {
			res += query(i, 0, ri[i][0], 0, 0, nn);
			res += query(i, ri[i][1],n,0 , 0, nn);
			if(ri[i][1]<=ri[i][0])res -= query(i, ri[i][1], ri[i][0], 0, 0, nn);
		}
		else if (ri[i][1] <= ri[i][0]) {
			res += query(i, 0, le[i][1], 0, 0, nn);
			res += query(i, le[i][0], n, 0, 0, nn);
			if(le[i][0]<=le[i][1])res -= query(i, le[i][0], le[i][1], 0, 0, nn);
		}
		else {
			int lele = max(le[i][0], ri[i][1]);
			int riri = min(le[i][1], ri[i][0]);
			int lel = min(le[i][0], ri[i][1]);
			int rir = max(le[i][1], ri[i][0]);
			res += query(i, 0, riri, 0, 0, nn);
			res += query(i, lele, n, 0, 0, nn);
			res += query(i, lel, rir, 0, 0, nn);
		}
		//cout << i << " " << res << endl;
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int  q; cin >> n >> q; init(n);
	string s; cin >> s;
	rep(i, n) {
		update(trans(s[i]), i, 1);
	}
	cout << ans() << endl;
	rep(i, q) {
		int x; char y; cin >> x >> y; x--;
		update(trans(s[x]),x, 0);
		s[x] = y;
		update(trans(s[x]), x, 1);
		cout << ans() << endl;
	}
	return 0;
}