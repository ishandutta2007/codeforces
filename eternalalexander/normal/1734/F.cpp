#include <bits/stdc++.h>

using ll = long long;
ll n,m,f[100][2][2][2];
int N[100],M[100];

void solve() {
	scanf("%lld%lld",&n,&m); 
	for (int i = 0; i < 65; ++ i) { M[i] = m % 2; m /= 2; }
	for (int i = 0; i < 65; ++ i) { N[i] = n % 2; n /= 2; }
	std::memset(f,0,sizeof(f));
	f[0][0][0][0] = 1;
	for (int i = 0; i <= 65; ++ i) {
		for (int j = 0; j < 2; ++ j)
		for (int k = 0; k < 2; ++ k)
		for (int l = 0; l < 2; ++ l) {
			for (int c = 0; c < 2; ++ c) {
				int cur = (N[i] + c + j) % 2;
				int nl = l;
				if (c > M[i]) nl = 0;
				else if (c < M[i]) nl = 1;
			//	assert((j + N[i] + c) / 2 <= 2);
				ll &t = f[i + 1][(j + N[i] + c) / 2][k ^ (cur != c)][nl];
				t += f[i][j][k][l];
			}
		}
	} printf("%lld\n",f[65][0][1][1]);
}
			

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}