#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
pii ptsr[505], ptsb[505];
int cnt[505][505];
short ccw(pii p0, pii p1, pii p2){
	ll cross = 1LL * (p1.fi - p0.fi) * (p2.se - p0.se) - 1LL * (p2.fi - p0.fi) * (p1.se - p0.se);
	if (cross < 0) return -1; if (cross > 0) return +1; return 0;
}
signed main(){
	fastio;
	short n, m; cin >> n >> m;
	for (short i = 0; i < n; i++) cin >> ptsr[i].fi >> ptsr[i].se;
	sort(ptsr, ptsr + n);
	for (short i = 0; i < m; i++) cin >> ptsb[i].fi >> ptsb[i].se;
	for (short i = 0; i < 505; i++) for (short j = 0; j < 505; j++) cnt[i][j] = 0;
	for (short i = 0; i < n; i++) for (int j = i + 1; j < n; j++){
		for (short k = 0; k < m; k++) if ((ptsr[i].fi <= ptsb[k].fi) && (ptsb[k].fi < ptsr[j].fi) && (ccw(ptsb[k], ptsr[i], ptsr[j]) < 0)) cnt[i][j]++;
		cnt[j][i] = -cnt[i][j];
	}
	int total = 0;
	for (short i = 0; i < n; i++) for (short j = i + 1; j < n; j++) for (short k = j + 1; k < n; k++) total += ((cnt[i][j] + cnt[j][k] + cnt[k][i]) == 0);
	cout << total << endl;
	return 0;
}