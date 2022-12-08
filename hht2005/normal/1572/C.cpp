#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int a[N],f[N][N],nxt[N],t[N];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			t[a[i]]=n+1;
		}
		for(int i=n;i>=1;i--) {
			nxt[i]=t[a[i]];
			t[a[i]]=i;
		}
		for(int l=2;l<=n;l++)
			for(int i=1;i+l-1<=n;i++) {
				int j=i+l-1;
				f[i][j]=min(f[i][j-1],f[i+1][j])+1;
				for(int k=nxt[i];k<=j;k=nxt[k])
					f[i][j]=min(f[i][j],f[i][k-1]+f[k][j]);
		}
		printf("%d\n",f[1][n]);
	}
	return 0;
}