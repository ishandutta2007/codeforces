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
const ll LINF = 2E18;		
const int MAXN = 55;
const int MOD = 1E9 + 7;

int n, a[MAXN];
ll k, dp[MAXN];

int main() {

	cin >> n >> k;

	dp[n] = 1;
	dp[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		/*
		if (dp[i + 1] + dp[i + 2] > LINF)
			dp[i] = LINF;
		else
		*/
			dp[i] = dp[i + 1] + dp[i + 2];	
		//db(dp[i]);
	}
	
	k--;
	
	//cout << dp[0] << '\n';
	
	for (int i = 0; i < n; ) {
		if (dp[i + 1] <= k) {
			k -= dp[i + 1];	
			a[i] = i + 1;
			a[i + 1] = i;
			i += 2;
		} else {
			a[i] = i;
			i++;	
		}
	}
	
	forn(i, n)
		cout << a[i] + 1 << " \n"[i == n - 1];
			
	return 0;
}