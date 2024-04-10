#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 6000;
int a[maxn], p[maxn];
int f[maxn][maxn];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	a[0] = -1E9;
	for(int i = 1; i <= n; i += 1) scanf("%d", a + i);
	sort(a, a + n + 1);
	for(int i = 1; i <= n; i += 1)
		for(p[i] = i; a[p[i]] + 5 >= a[i]; p[i] -= 1);
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= k; j += 1)
			f[i][j] = max(f[i - 1][j], f[p[i]][j - 1] + i - p[i]);
	printf("%d", f[n][k]);
}