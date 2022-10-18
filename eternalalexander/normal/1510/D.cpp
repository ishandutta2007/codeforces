#include <bits/stdc++.h>
const int maxn = 1e5 + 22;

int n,d,a[maxn],s[maxn][12],vis[maxn][12];
double f[maxn][12],w[maxn];
std::vector<int>vec;

void output(int n,int d) {
	if (n == 0) return;
	if (vis[n][d] || (a[n] == 1)) vec.push_back(a[n]);
	output(n-1,s[n][d]);
}

void update(int i,int j,int k,int l,long double v,int c) {
	if (f[k][l] < f[i][j] + v) {
		f[k][l] = f[i][j] + v;
		s[k][l] = j;
		vis[k][l] = c;
	}
}

int main() {
	scanf("%d%d",&n,&d);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		w[i] = std::log(a[i]);
	}
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j < 10; ++ j) f[i][j] = -1e9;
	f[0][1] = 0;
	for (int i = 1; i <= n; ++ i) {
		int c = a[i] % 10;
		for (int j = 0; j < 10; ++ j) {
			update(i-1,j,i,j,0,0);
			update(i-1,j,i,(j*c)%10,w[i],1);
		} 
	} if (f[n][d] < 0) { puts("-1"); return 0; }
	output(n,d);
	if (vec.size() == 0) { puts("-1"); return 0; }
	printf("%d\n",vec.size());
	for (int x:vec) printf("%d ",x);
	return 0;
}