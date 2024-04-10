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
const ll LINF = 1E18;
const int MAXN = 10500;

int n, x, sz, id;
pii a[MAXN];
int coord[MAXN];
ll dp[2][MAXN], ans;

int main() {

	scanf("%d%d", &n, &x);
	sz = 0;
	coord[sz++] = x;
	
	forn(i, n) {
		scanf("%d%d", &a[i].X, &a[i].Y);
		coord[sz++] = a[i].X;
		coord[sz++] = a[i].Y;
	}
	
	sort(coord, coord + sz);
	sz = unique(coord, coord + sz) - coord;
	
	int id = lower_bound(coord, coord + sz, x) - coord;
	forn(i, sz)
		dp[0][i] = abs(coord[i] - coord[id]);
	id = 0;
	
	forn(i, n) {
		forn(j, sz)
			dp[id ^ 1][j] = LINF;
			
		int L = lower_bound(coord, coord + sz, a[i].X) - coord;
		int R = lower_bound(coord, coord + sz, a[i].Y) - coord;
	
		for (int j = L; j <= R; j++) {
			dp[id ^ 1][j] = min(dp[id ^ 1][j], dp[id][j]);
		}
		
		ll curMin = LINF;
		for (int j = 0; j <= L; j++) {
			curMin = min(curMin, dp[id][j] + abs(coord[L] - coord[j]));
			dp[id ^ 1][j] = min(dp[id ^ 1][j], curMin);
		}
		
		curMin = LINF;
		for (int j = sz - 1; j >= R; j--) {
			curMin = min(curMin, dp[id][j] + abs(coord[R] - coord[j]));
			dp[id ^ 1][j] = min(dp[id ^ 1][j], curMin);
		}
		
		id ^= 1;
	}
	
	ans = LINF;
	forn(i, sz)
		ans = min(ans, dp[id][i]);
	cout << ans;
	
	return 0;
}