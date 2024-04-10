#include <bits/stdc++.h>
#define ll long long
#define maxn 22 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int mxs = 2005;
bitset<mxs> r[1 << 16];
int s[maxn];
int n, k; 
int x[maxn];
int dep[maxn];
void otp(vector<pi> r) {
	//dep 
	if (r.size() == 1) return ;
//	cout << r.size() << endl;
	sort(r.begin(), r.end());
	pi u1 = r[r.size() - 1], u2 = r[r.size() - 2];
	cout << u1.se << ' ' << u2.se << endl;
	if (u1.fi != u2.fi) exit(1);
	u1.se += u2.se;
	while (u1.se % k == 0)
		u1.se /= k, u1.fi--;
	r[r.size() - 2] = u1;
	r.resize(r.size() - 1);
	otp(r);
}
void cal(int a, int b, int ndep) {
	if (!a) return ;
//	cout << a << ' ' <<b << ' ' << ndep << endl;
	if (b * k < mxs && r[a][b * k]) cal(a, b * k, ndep + 1);
	else {
		for (int j = 0; j < n; j++) {
			if (a & (1 << j)) 
				if (b >= x[j] && r[a ^ (1 << j)][b - x[j]] == 1) {
					dep[j] = ndep;
					cal(a ^ (1 << j), b - x[j], ndep);
					break;
				}
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < (1 << n); i++) {
		if (i == 0) r[i][0] = 1;
		else {
			for (int j = 0; j < n; j++) 
				if (i & (1 << j)) r[i] |= (r[i ^ (1 << j)] << x[j]);
			for (int j = mxs - 1; j >= 0; j--)
				if (j * k < mxs && r[i][j * k]) r[i][j] = 1;
		}
	}
	if (!r[(1 << n) - 1][1]) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cal((1 << n) - 1, 1, 0);
	//	cout << "AF" << endl;
		vector<pi> u;
		for (int i = 0; i < n; i++)
			u.pb(mp(dep[i], x[i])); 
	//		cout << "PB" << u.size() << endl;
		otp(u);
	}
	return 0;
}