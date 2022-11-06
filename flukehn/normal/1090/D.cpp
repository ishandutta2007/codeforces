#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int Read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >='0' && ch <='9'){x = x*10 + ch - '0'; ch = getchar();}
	return x*f;
}
int n, m;
int a[100005], zd[100005], zx[100005], hed, til, t, x[100005], y[100005];

int main() {
	cin >> n >> m;
	int i, u, v, j;
	hed = 1, til = n;
	t = 700;for(i = 1; i <= m; ++i)cin >> x[i] >> y[i];
	while(t--) {
	for(i = 1; i <= n; ++i) a[i] = i;
	random_shuffle(a + 1, a + n + 1);
	for(i = 1; i <= n; ++i) zx[i] = 1, zd[i] = n;
	for(i = 1; i <= m; ++i) {
		u = x[i], v = y[i];
		if(a[u] > a[v]) swap(u, v);
		if(u == v) continue;
		zd[u] = min(zd[u], a[v] - 1);
		zx[v] = max(zx[v], a[u] + 1);
	}
	for(i = 1; i <= n; ++i) {
		if(zd[i] < zx[i]) {
			puts("NO");
			return 0;
		}
	}
	for(i = 1; i <= n; ++i) {
		if(zd[i] < zx[i]) {
			puts("NO");
			return 0;
		}
		if(zx[i] != a[i]) {
			puts("YES");
			for(j = 1; j <= n; ++j) cout << a[j] << " ";
			cout << endl;
			for(j = 1; j <= n; ++j) {
				if(i != j) cout << a[j] << " ";		
				else cout << zx[i] << " ";
			}
			return 0;
		}
		if(zx[i] + 1 > zd[i]) continue;
		puts("YES");
		for(j = 1; j <= n; ++j) cout << a[j] << " ";
		cout << endl;
		for(j = 1; j <= n; ++j) {
			if(i != j) cout << a[j] << " ";		
			else cout << zx[i] + 1 << " ";
		}
		return 0;
	}
	}
	puts("NO");
}