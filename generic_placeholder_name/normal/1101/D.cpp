#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
int dow[200005][165]; 
int w[200005]; 
vector <int> adj[200005], divs[200005]; 
int ans = 0;
void dfs(int u, int p){
	for (int v : adj[u]){
		if (v == p) continue; dfs(v, u);
	}
	for (int i = 0; i < divs[w[u]].size(); i++){
		int d = divs[w[u]][i];
		if (d == 1) continue;
		int mx1 = 0, mx2 = 0; 
		for (int v : adj[u]){
			int id = lower_bound(divs[w[v]].begin(), divs[w[v]].end(), d) - divs[w[v]].begin();
			if (divs[w[v]][id] != d) continue;
			int val = dow[v][id];
			dow[u][i] = max(dow[u][i], val);
			if (mx1 < val) mx2 = mx1, mx1 = val;
			else if (mx2 < val) mx2 = val;
		}
		dow[u][i]++; ans = max(ans, mx1 + mx2 + 1);
	}
} 
int main(){
	fastio;
	int n; cin >> n;
	//based on https://codeforces.com/contest/1101/submission/84936420
	//making a fairly obvious (?) optimization here
	//since we only care if gcd=1 or not, enumerating over primes should be enough
	//complexity O(n*d(A) log d(A)) -> O(n log A log log A)
	for (int i = 1; i < 200005; i++){
	    if(divs[i].size()<2) { //empty(1) or prime(only divisor is 1)
		    for (int j = i; j < 200005; j += i) divs[j].pb(i);
	    }
	}
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(0, 0);
	cout << ans << endl;
}