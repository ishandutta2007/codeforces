//Author: Heltion
//Date: 2019-06-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 240000;
LL a[maxn], b[maxn], ta, tb;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> ta >> tb >> k;
	if(k >= n or k >= m) no(-1);
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= m; i += 1) cin >> b[i];
	LL ans = 0;
	for(int i = 1; i <= n and i <= k + 1; i += 1){
		int j = lower_bound(b + 1, b + m + 1, a[i] + ta) - b;
		if(j + k - i + 1 > m) no(-1);
		ans = max(ans, b[j + k - i + 1] + tb);
	}
	cout << ans;
	return 0;
}