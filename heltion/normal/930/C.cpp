#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
int a[maxn], f[maxn], g[maxn], s[maxn], n, m;
int sum(int x){
	int res = 0;
	for(x += 1; x; x -= x & -x) res = max(res, s[x]);
	return res;
}
void add(int x, int d){
	for(x += 1; x <= n + 1; x += x & -x) s[x] = max(s[x], d);
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1){
    	int l, r;
    	cin >> l >> r;
    	a[l] += 1;
    	a[r + 1] -= 1;
	}
	for(int i = 1; i <= m; i += 1) a[i] += a[i - 1];
	for(int i = 1; i <= m; i += 1){
		f[i] = sum(a[i]) + 1;
		add(a[i], f[i]);
	}
	memset(s, 0, sizeof s);
	reverse(a + 1, a + m + 1);
	for(int i = 1; i <= m; i += 1){
		g[i] = sum(a[i]) + 1;
		add(a[i], g[i]);
	}
	int ans = 0;
	for(int i = 1; i <= m; i += 1) ans =  max(ans, f[i] + g[m - i + 1] - 1);
	cout << ans;
}