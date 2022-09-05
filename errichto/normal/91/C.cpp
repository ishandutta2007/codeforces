#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
const int nax = 1e6 + 5;
int par[nax];
int find(int a) {
	if(a == par[a]) return a;
	return par[a] = find(par[a]);
}
void uni(int a, int b) {
	par[find(a)] = find(b);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) par[i] = i;
	int ans = 1;
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = find(a);
		b = find(b);
		if(a == b) ans = 2 * ans % mod;
		else {
			uni(a, b);
		}
		printf("%d\n", (ans + mod - 1) % mod);
	}
	return 0;
}