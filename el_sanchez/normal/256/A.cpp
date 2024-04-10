#pragma comment(linker, "/STACK:67108864")
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)
 
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
 
using namespace std;
 
typedef long long ll;
 
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 4010;
const int MAXM = 1000010;

int n, k;
int a[MAXN];
int dp[MAXN][MAXN];
int curl[MAXM], id[MAXM], ans;
vector<vi> ind(MAXN);
int f[MAXM];

int main() {
 
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
 
	k = 0;
	forn(i, MAXM) {
		id[i] = -1;
		curl[i] = INF;
	}
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
		if (id[a[i]] == -1)
			id[a[i]] = k++;
	}

	forn(i, n) {
		if (ind[id[a[i]]].empty())
			curl[a[i]] = i;
		ind[id[a[i]]].push_back(i);
	}

	if (n == 1) {
		cout << 1;
		return 0;
	}
	forn(i, n)
		forab(j, i + 1, n)
			dp[i][j] = 2;

	f[a[0]]++;
	if (ind[id[a[0]]].size() == 1)
		curl[a[0]] = INF;
	else {		
		curl[a[0]] = ind[id[a[0]]][f[a[0]]];
	}

	for (int a2 = 1; a2 < n; a2++) {
		f[a[a2]]++;
		if (f[a[a2]] == ind[id[a[a2]]].size())
			curl[a[a2]] = INF;
		else
			curl[a[a2]] = ind[id[a[a2]]][f[a[a2]]];
		for (int a1 = 0; a1 < a2; a1++) {
			if (dp[a1][a2] > 0 && curl[a[a1]] < n)
				dp[a2][curl[a[a1]]] = max(dp[a2][curl[a[a1]]], dp[a1][a2] + 1);
		}
	}
	ans = 0;
	forn(i, n)
		forn(j, n)
			ans = max(dp[i][j], ans);
	cout << ans;

    return 0;
}