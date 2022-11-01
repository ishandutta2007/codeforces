#include <bits/stdc++.h>
#define N 5050
using namespace std;
typedef long long LL;
int n,a[N],vis[N],sum[N],F[N][N],g[N],cnt[N],cur[N];
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd(), cnt[a[i]]++;
	for (int i=1;i<=n;i++) {
		int tot = 0;
		for (int _=0;_<=5000;_++) cur[_] = 0;
		for (int j=i;j<=n;j++) {
			cur[a[j]]++;
			if (cur[a[j]] == 1) {
				if (cur[a[j]] != cnt[a[j]]) tot++;
			} else {
				if (cur[a[j]] == cnt[a[j]]) tot--;
			}
			if (!tot) F[i][j] = 1;
		}
	}
	for (int i=1;i<=n;i++) {
		sum[i] = sum[i-1];
		if (!vis[a[i]]) vis[a[i]] = 1, sum[i]^=a[i];
	}

	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++) {
			g[i] = max(g[i], g[j-1]);
			if (F[j][i]) g[i] = max(g[i], g[j-1] + (sum[i]^sum[j-1]));
		}
	cout << g[n] << endl;
	return 0;
}