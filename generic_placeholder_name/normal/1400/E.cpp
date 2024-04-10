//448C


#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define debug cerr <<
#define ll long long
#define int long long
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define pb push_back
#define eb emplace_back
#define Size(v) (int)v.size()

using namespace std;
// using namespace __gnu_pbds;

// Always
const int nax = 5e3+5, INF = 1e16;
int n;
int a[nax];

int solve(int l,int r,int m){
	int mini=INF;
	FOR (i, l, r) mini = min(mini, a[i]-m);
	int res1=0;
	FOR (i, l, r) if (a[i] - m > 0) res1++;
	int res2 = mini;
	FOR (i, l, r) {
		if (a[i] - m - mini == 0)continue;
		int L = i;
		while (i + 1 <=r && a[i+1] - m - mini > 0) i++;
		res2 += solve(L, i, m + mini);
	}
	return min(res1, res2);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	FOR (i, 1, n) cin>>a[i];
	cout << solve(1, n, 0);
}