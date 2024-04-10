#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;
const int S = 6;
const int SZ = S * S * 8;

void print(ll a[S][S])  {
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) cerr << a[i][j] << ' '; cerr << '\n';
	}
	cerr << '\n';
}


void mult(ll a[S][S], ll b[S][S], ll c[S][S], ll m) {
	memset(c, 0, SZ);
	for(int k = 0; k < S; k++) {
		for(int i = 0; i < S; i++) {
			for(int j = 0; j < S; j++) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= m;
			}
		}
	}
}

ll A[S][S] = {
	{2, 1, 1, 0, 1, 0},
	{1, 2, 0, 1, 1, 0},
	{1, 1, 1, 0, 1, 0},
	{1, 1, 0, 1, 1, 0},
	{0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 1}
};

ll t[S][S];
ll s[S][S];
ll p[S][S];
void exp(ll a[S][S], ll e, ll res[S][S], ll m) {
	memcpy(p, a, SZ);
	memset(res, 0, SZ);
	for(int i = 0; i < S; i++) {
		res[i][i] = 1;
	}
	while(e) {

		if(e % 2) {
			memcpy(t, res, SZ);
			mult(p, t, res, m);
		}

		memcpy(t, p, SZ);
		memcpy(s, p, SZ);
		mult(s, t, p, m);

		e /= 2;
	}
}

long long N, Sx, Sy, Dx, Dy, T;

ll val[S][S];
pair<int, int> go() {
	exp(A, T, val, N);
	ll x = 0;
	ll y = 0;
	x += val[0][0] * Sx;
	x += val[0][1] * Sy;
	x += val[0][2] * Dx;
	x += val[0][3] * Dy;
	x += val[0][4] * 0; //T = 0
	x += val[0][5] * 1;
	x %= N;
	if(x <= 0) x += N;
	y += val[1][0] * Sx;
	y += val[1][1] * Sy;
	y += val[1][2] * Dx;
	y += val[1][3] * Dy;
	y += val[1][4] * 0; //T = 0
	y += val[1][5] * 1;
	y %= N;
	if(y <= 0) y += N;
	return make_pair(x, y);
}

void test(int t, int m = 1e9 + 7) {
	exp(A, t, val, m);
	print(val);
}

int main() {
	cin >> N >> Sx >> Sy >> Dx >> Dy >> T;
	pair<int, int> res = go();
	cout << res.first << ' ' << res.second << '\n';
	return 0;
}