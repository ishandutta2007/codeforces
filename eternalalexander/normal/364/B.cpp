#include <bits/stdc++.h>

using ll = long long;
const ll inf = 9e18;
const int lim = 5e5+1;

int n,d,c[55],s[55],pre[500010];
std::bitset<500010>B;

int main() {
	scanf("%d%d",&n,&d);
	for (int i = 1; i <= n; ++ i) scanf("%d",&c[i]);
	B[0] = 1;
	for (int i = 1; i <= n; ++ i) B = B | (B << c[i]);
	for (int i = 0; i <= lim; ++ i) {
		if (B[i]) pre[i] = i;
		else pre[i] = pre[i-1];
	}
	int x = 0, y = 0;
	while (1) {
		int nxt = pre[std::min(lim,x + d)];
		if (nxt <= x) { printf("%d %d\n",x,y); return 0; }
		x = nxt; y++;
	}
	return 0;
}