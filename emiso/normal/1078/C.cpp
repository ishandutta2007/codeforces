#include <bits/stdc++.h>

#define MOD 998244353 
#define MN 300030

using namespace std;
typedef long long ll;

int dp[MN][3];
vector<int> adj[MN];

ll expo(ll a, ll b) {
	if(!b) return 1;
	a %= MOD;
	if(b & 1) return a * expo(a * a, b >> 1) % MOD;
	return expo(a * a, b >> 1);
}

ll inv_mod(ll x) { return expo(x, MOD - 2); }

int solve(int no, int kind, int pai = -1) {
	int &x = dp[no][kind];
	if(x != -1) return x;
	x = 0;
	
	ll mult = 1;
	for(int v : adj[no]) {
		if(v == pai) continue;
		mult = mult * solve(v, 0, no) % MOD;
	}
	
	if(kind == 0) {
		x = mult;
		
		mult = 1;
		for(int v : adj[no]) {
			if(v == pai) continue;
			mult = mult * (solve(v, 0, no) + solve(v, 1, no)) % MOD;
		}
		
		for(int v : adj[no]) {
			if(v == pai) continue;
			x += mult * inv_mod(solve(v, 0, no) + solve(v, 1, no)) % MOD * solve(v, 2, no) % MOD;
			if(x >= MOD) x -= MOD;
		}
	} else if(kind == 1) {
		mult = 1;
		for(int v : adj[no]) {
			if(v == pai) continue;
			mult = mult * (solve(v, 0, no) + solve(v, 1, no)) % MOD;
		}
		
		for(int v : adj[no]) {
			if(v == pai) continue;
			x += mult * inv_mod(solve(v, 0, no) + solve(v, 1, no)) % MOD * solve(v, 2, no) % MOD;
			if(x >= MOD) x -= MOD;
		}
	} else if(kind == 2) {
		mult = 1;
		for(int v : adj[no]) {
			if(v == pai) continue;
			mult = mult * (solve(v, 0, no) + solve(v, 1, no)) % MOD;
		}
		
		x += mult;
		if(x >= MOD) x -= MOD;
	}
	return x;
}

int n, a, b;

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%d\n", solve(1, 0));
	return 0;
}