//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
constexpr int maxn = 240000;
int a[maxn], p[maxn], dp[maxn][20], ans = 0;
int query(int l, int r){
	for(int j = 19; ~j; j -= 1)
		if(l + (1 << j) - 1 <= r){
			int x = dp[l][j], y = dp[r - (1 << j) + 1][j];
			if(a[x] > a[y]) return x;
			return y;
		}
	return 0;
}
void solve(int l, int r){
	if(l >= r) return;
	int m = query(l, r);
	if(r - m < m - l)
		for(int j = m + 1; j <= r; j += 1){
			int x = p[a[m] - a[j]];
			if(x >= l and x < m) ans += 1;
		}
	else for(int j = l; j < m; j += 1){
		int x = p[a[m] - a[j]];
			if(x <= r and x > m) ans += 1;
	}
	solve(l, m - 1);
	solve(m + 1, r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		p[a[i]] = i;
	}

	for(int j = 0; j < 20; j += 1)
		for(int i = 1; i <= n; i += 1) if(j == 0) dp[i][j] = i;
		else if((i + (1 << j) - 1) <= n){
			int x = dp[i][j - 1], y = dp[i + (1 << (j - 1))][j - 1];
			if(a[x] > a[y]) dp[i][j] = x;
			else dp[i][j] = y;
		}
	solve(1, n);
	cout << ans;
	return 0;
}