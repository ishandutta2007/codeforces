//#define _GLIBCXX_DEBUG
//#include <bits/stdc++.h>

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
const int MAXN = 300500;
const int MAXK = 5111;

int n, k;
int a[MAXN], d[MAXN];
ll dp[MAXK][MAXK], sum, num[2], len[2];

int main() {

	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	
	sum = 0;
	forn(i, n - 1) {
		d[i + 1] = a[i + 1] - a[i];
		sum += d[i + 1];
	}
	
	num[0] = n % k;      //+(n+k-1)/k
	num[1] = k - num[0]; //+(n-1)/k
	len[0] = n / k + 1;
	len[1] = len[0] - 1;
	/*
	db(num[0]);
	db(num[1]);
	db(len[0]);
	db(len[1]);		
	*/
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	forn(i, num[0] + 1)
		forn(j, num[1] + 1)
			if (dp[i][j] != -1) {
				int curPos = i * len[0] + j * len[1];
				if (i < num[0])
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + d[curPos + len[0]]);
				if (j < num[1])
					dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + d[curPos + len[1]]);
			}
			
	cout << sum - dp[num[0]][num[1]];
	
	return 0;
}