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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 4010;
const int MOD = 1E9 + 7;

ll C[MAXN][MAXN];
ll dp[MAXN][MAXN], ans, sum;
int n;

int main() {

	cin >> n;
	C[0][0] = 1;
	forab(i, 1, MAXN)
		C[0][i] = 0;
	forab(i, 1, MAXN) {
		C[i][0] = 1;
		forab(j, 1, MAXN)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int num = 0; num < n; num++)
			if (dp[i][num]) {
				dp[i + 1][num] = (dp[i + 1][num] + dp[i][num] * num) % MOD;
				dp[i + 1][num + 1] = (dp[i + 1][num + 1] + dp[i][num]) % MOD;
			}		
	ans = 0;
	
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int num = 0; num < n; num++)
			sum = (sum + dp[i][num]) % MOD;
		sum = (sum * C[n][i]) % MOD;
		ans = (ans + sum) % MOD;	
	}

	cout << ans;		
	
	return 0;
}