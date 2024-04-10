#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif
 
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
 
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

LL f[maxn];
 
int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m, w, c;
	LL d, h;
	
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> w >> d >> h;
		f[w] = max(f[w], d * h);
	}
	
	for (int i = 1; i <= c; i++) {
		if (f[i] == 0) continue;
		for (int j = i + i; j <= c; j += i) {
			f[j] = max(f[j], f[i] * (j / i));
		}
	}
	
	for (int i = 1; i <= c; i++) f[i] = max(f[i], f[i - 1]);
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> d >> h;
		d *= h;
		
		int ans = upper_bound(f + 1, f + c + 1, d) - f;
		if (ans <= c) cout << ans << " ";
		else cout << -1 << " ";
	}
 
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}