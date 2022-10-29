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
const int MAXN = 2000500;
const int MOD = 1E9 + 7;

ll inv(ll x) {
	ll res = 1, pw = MOD - 2;
	while (pw > 0) {
		if (pw & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		pw >>= 1;	
	}	
	return res;}

int n;
ll ans, pw2[MAXN], f[MAXN], Cn[MAXN], d, cur;

int main() {

	cin >> n;
	pw2[0] = 1;
	forab(i, 1, MAXN)
		pw2[i] = (pw2[i - 1] * 2) % MOD;	
	
	ans = (pw2[2 * n + 1] + MOD - 1) % MOD;
	
	f[0] = 1;
	for (int i = 1; i <= 2 * n; i++)
		f[i] = (f[i - 1] * i) % MOD;
		
	//db(ans);
	
	d = 0;
	for (int i = 0; i < n; i++) {
		int h = n + 1 + i;
		cur = (pw2[2 * n - h + 1] + MOD - 1) % MOD;
        cur = (cur * f[n + i] % MOD * inv(f[n]) % MOD * inv(f[i]) % MOD) % MOD;
        
        //db(cur);
        
		d = (d + cur) % MOD;	
	}
			
	ans = (ans - d * 2 + 2 * MOD) % MOD;
	
	cout << ans;
	
	return 0;
}