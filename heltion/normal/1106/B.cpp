#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
LL a[maxn], c[maxn];
int b[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) cin >> c[i];
	for(int i = 1; i <= n; i += 1) b[i] = i;
	sort(b + 1, b + n + 1, [&](const int &x, const int &y){
		if(c[x] == c[y]) return x < y;
		return c[x] < c[y];	
	});
	int L = 1;
	for(int i = 0; i < m; i += 1){
		LL t, d, ans = 0;
		cin >> t >> d;
		LL h = min(a[t], d);
		a[t] -= h, d -= h, ans += h * c[t];
		while(L <= n && d){
			h = min(a[b[L]], d);
			a[b[L]] -= h, d -= h,ans += h * c[b[L]];
			if(a[b[L]] == 0) L += 1; 
		}
		if(d) cout << 0 << endl;
		else cout << ans << endl;
	}
}