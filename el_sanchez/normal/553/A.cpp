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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 1111;
const int MOD = 1E9 + 7;

int k, n;
int a[MAXN], sum[MAXN];
ll dp[MAXN][MAXN], f[MAXN], ans;

ll inv(ll x) {
	ll res = 1, pw = MOD - 2;
	while (pw > 0) {
		if (pw & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		pw >>= 1;	
	}
	return res;
}

int main() {

	cin >> k;
	forn(i, k)
		cin >> a[i];
	reverse(a, a + k);
	sum[0] = a[0];
	forab(i, 1, k)
		sum[i] = sum[i - 1] + a[i];
	n = sum[k - 1];	
			
	f[1] = 1;
	forab(i, 2, n + 1) {
		f[i] = (f[i - 1] * inv(i)) % MOD;	
	}
	
	dp[1][0] = a[0];
	for (int i = 1; i < n; i++)
		for (int last = 0; last < k; last++)
			if (dp[i][last] > 0) {
				if (last != k - 1)
					dp[i + 1][last + 1] = (dp[i + 1][last + 1] + dp[i][last] * a[last + 1]) % MOD;
				ll variants = sum[last] - i;
				dp[i + 1][last] = (dp[i + 1][last] + dp[i][last] * variants) % MOD;	
			}
		
//	for (int i = 1; i <= 4; i++)
//		db(inv(f[i]));
		
	ans = dp[n][k - 1];
	forn(i, k)
		ans = (ans * f[a[i]]) % MOD;
	cout << ans;
		
	return 0;
}