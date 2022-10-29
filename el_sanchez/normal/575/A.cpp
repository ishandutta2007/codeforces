//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
*/			   
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 50100;
const int MAXK = 65536;

struct matrix {
	int a[2][2];
	
	matrix() {
		memset(a, 0, sizeof(a));
	}
	
	matrix(int x1, int x2, int y1, int y2) {
		a[0][0] = x1;
		a[0][1] = x2;
		a[1][0] = y1;
		a[1][1] = y2;
	}
	
	void print() {
		forn(i, 2)
			forn(j, 2)
				cout << a[i][j] << " \n"[j == 1];
		cout << '\n';	
	}
};

int n, m;
ll cur;
ll k, P;               
int s[MAXN], modS[MAXN];
int v[2];
pair<ll, int> pos[MAXN];
                      
matrix t[2 * MAXK + 3];
matrix E(1, 0, 0, 1), M;

matrix operator*(matrix M, matrix N) {
	matrix res;
	forn(i, 2)
		forn(j, 2)
			forn(k, 2)
				res.a[i][j] = (res.a[i][j] + 1ll * M.a[i][k] * N.a[k][j]) % P;
	return res;
}

void apply(matrix M) {
	int tv[2];
	forn(i, 2)
		tv[i] = (1ll * M.a[0][i] * v[0] + 1ll * M.a[1][i] * v[1]) % P;	
	forn(i, 2)
		v[i] = tv[i];
}

matrix pw(matrix M, ll st) {
	matrix res = E;
	while (st > 0) {
		if (st & 1)
			res = res * M;
		M = M * M;
		st >>= 1;	
	}
	return res;
}

void build() {
	for (int i = 0; i < n; i++) {
		int v = MAXK + i;
		t[v] = matrix(0, s[i], 1, s[(i + 1) % n]);	
	}
	for (int i = n; i < MAXK; i++) {
		int v = MAXK + i;
		t[v] = matrix(1, 0, 0, 1);		
	}
	
	for (int v = MAXK - 1; v >= 1; v--) {
		t[v] = t[v * 2] * t[v * 2 + 1];	
	}
}

matrix get(int v, int lv, int rv, int L, int R) {
	if (rv <= L || R <= lv)
		return E;
	if (L <= lv && rv <= R)
		return t[v];
	return get(v * 2, lv, (lv + rv) >> 1, L, R) * get(v * 2 + 1, (lv + rv) >> 1, rv, L, R); 
}

matrix get(int L, int R) { //[L..R)
 	return get(1, 1, MAXK + 1, L + 1, R + 1); 
}

void evaluate(ll L, ll R) { //[L..R] 
	//printf("calc [%I64d..%I64d]\n", L, R);
	
	ll M2 = R / n * n;
	if (M2 <= L) {
		apply(get(L % n, R % n + 1));
	} else {
		//cout << L % n << "..." << n << '\n';
		
		apply(get(L % n, n));
		
		ll M1 = L / n * n;
		M1 += n;
		
		ll len = (M2 - M1) / n;
		if (len > 0) {
			M = pw(t[1], len);
			apply(M);				
		}
				
		apply(get(0, R % n + 1));
		
		//cout << 0 << "..." << R % n + 1 << '\n';
		
	}
	
//	db(v[1]);
}

int main() {

	cin >> k >> P;
	
	if (P == 1) {
		cout << 0;
		return 0;
	}
	
	cin >> n;
	forn(i, n) {
		scanf("%d", &s[i]);
		s[i] %= P;
	}		
	cin >> m;
	forn(i, m) {
		scanf("%I64d%d", &pos[i].X, &pos[i].Y);
		pos[i].Y %= P;
	}
	sort(pos, pos + m);		
		
	v[0] = 0;
	v[1] = 1;
	
	if (k <= 1) {
		cout << v[k];
		return 0;
	}
	
	k -= 2;
	cur = 0;
	
	//build matrix tree
	build();
	
	//evaluate
	ll prevCh = -INF;	
	for (int i = 0; i < m; i++) {
		ll leftCh = pos[i].X - 1;
		if (leftCh > k)
			break;
		
		if (cur < leftCh) {
			evaluate(cur, leftCh - 1);
			cur = leftCh;								
		}
		
		if (cur > k)
			break;
		
		if (prevCh == leftCh) {
			//printf("0calc [%I64d..%I64d]\n", cur, cur);
	
			M = matrix(0, pos[i - 1].Y, 1, pos[i].Y);
			apply(M);
			cur++;	
		} else {
			//printf("1calc [%I64d..%I64d]\n", cur, cur);
			
			M = matrix(0, s[(pos[i].X + n - 1) % n], 1, pos[i].Y);
			apply(M);
			cur++;	
		}
		
		//M.print();
		
		if (cur > k)
			break;
			
		if (i == m - 1 || pos[i].X + 1 < pos[i + 1].X) {
			//printf("calc [%I64d..%I64d]\n", cur, cur);
			
			M = matrix(0, pos[i].Y, 1, s[(pos[i].X + 1) % n]);
			apply(M);
			cur++;	
			
			//M.print();
		}	
		
		prevCh = pos[i].X;
	}
	
	if (cur <= k)
		evaluate(cur, k);
	assert(cur <= k + 1);
	
	cout << v[1];
	
	return 0;
}