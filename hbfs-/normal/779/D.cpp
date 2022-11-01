#include <bits/stdc++.h>
#define N 200050

using namespace std;
inline int rd() { int r; scanf("%d",&r); return r; }
int n,m,ans,l,h,p,vis[N],a[N];
char s[N],t[N];

bool go(int x) {
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=x;i++) vis[ a[i] ] = 1;
	int h = 1;
	for (int i=1;i<=m;i++) {
		while ((h+1 <= n) && (vis[h] || s[h] != t[i])) h++;
		if (vis[h] || s[h] != t[i]) return 0;
		h++;
	}
	return 1;
}

int main() {
	scanf("%s",s+1); n = strlen(s+1);
	scanf("%s",t+1); m = strlen(t+1);
	for (int i=1;i<=n;i++) a[i] = rd();
	int l = 0 , r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (go(mid)) l = mid; else r = mid - 1;
	}
	printf("%d\n",l);
	return 0;
}