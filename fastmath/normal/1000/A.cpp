#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>
         
using namespace std;
 
const int MAXN = 107;

string a[MAXN], b[MAXN];
map <string, int> d1, d2;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];


	for (int i = 0; i < n; ++i) {
	 	++d1[a[i]];
	 	++d2[b[i]];
	}

	int ans = 0;
	ans += d1["S"] + d1["M"] + d1["L"] - min(d1["S"], d2["S"]) - min(d1["M"], d2["M"]) - min(d1["L"], d2["L"]);
	ans += d1["XS"] + d1["XL"] -  min(d1["XS"], d2["XS"]) - min(d1["XL"], d2["XL"]);
	ans += d1["XXS"] + d1["XXL"] -  min(d1["XXS"], d2["XXS"]) - min(d1["XXL"], d2["XXL"]);
	ans += d1["XXXS"] + d1["XXXL"] -  min(d1["XXXS"], d2["XXXS"]) - min(d1["XXXL"], d2["XXXL"]);

	cout << ans << '\n';
    return 0;
}