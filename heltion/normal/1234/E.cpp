#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
LL ans[maxn], a[maxn];
void add(int L, int R, LL x){
	ans[L] += x;
	ans[R + 1] -= x;
}
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i += 1) cin >> a[i];
	for(int i = 1; i < m; i += 1){
		LL x = a[i], y = a[i + 1];
		if(x == y) continue;
		if(x > y) swap(x, y);
		if(x > 1) add(1, x - 1, y - x);
		if(y < n) add(y + 1, n, y - x);
		if(x + 1 < y) add(x + 1, y - 1, y - x - 1);
		add(x, x, y - 1);
		add(y, y, x);
	}
	for(int i = 1; i <= n; i += 1){
		ans[i] += ans[i - 1];
		cout << ans[i] << " ";
	}
}