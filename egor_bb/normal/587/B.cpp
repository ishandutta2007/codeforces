#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
 
typedef long long ll;
typedef unsigned long long ull;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int N = int(1e6) + 100;
const int M = int(1e5) + 10;
const int MOD = int(1e9) + 7;
const ll pwr = int(1e9) + 5;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define pb push_back
#define problem "test"
#define sz(A) int(A.size())
#define forn(i, n) for (int i = 0; i < n; i++) 


using namespace std;

ll n, l, k, a[N], b[N];
vector < vector <ll> > dp;

int main() {
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	scanf("%I64d%I64d%I64d", &n, &l, &k);
	dp.assign(n, vector <ll> (k + 1, 0));
	forn(i, n)
		scanf("%I64d", &a[i]), b[i] = a[i];
	sort (a, a + n);
	forn(i, n)
		dp[i][1] = 1;
	for(int j = 2; j <= k; j++){
		ll sum = 0, x = 0;
		forn(i, n){
			while (x < n && a[x] <= a[i]){
				sum = (sum + dp[x][j - 1]) % MOD;
				x++;
			}
			dp[i][j] = sum;
		}
	}
	ll ans = 0, d = l / n, x = l % n;
	forn(i, n){
		for (ll j = 1; j <= min(k, d); j++){
			ans = (ans + dp[i][j] * ((d - j + 1) % MOD)) % MOD;
		}
	}
	forn(i, x){
		ll f = lower_bound(a, a + n, b[i]) - a;
		for (int j = 1; j <= min(k, d + 1); j++){
			ans = (ans + dp[f][j]) % MOD;
		}
	}
	printf("%I64d\n", ans);
}