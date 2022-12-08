#include<bits/stdc++.h>
using namespace std;
const int N=410;
char s[N][N];
int f[N],v[N],a[N][N];
int main() {
	int n,m,T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
				a[i][j]=s[i][j]-'0'+a[i][j-1];
		}
		int ans=1e9;
		for(int i=1;i<=m;i++)
			for(int j=i+3;j<=m;j++) {
				int Min=1e9;
				for(int k=1;k<=n;k++) {
					f[k]=j-1-i-a[k][j-1]+a[k][i];
					v[k]=a[k][j-1]-a[k][i]+(s[k][i]=='0')+(s[k][j]=='0')+v[k-1];
					if(k>4)Min=min(Min,f[k-4]-v[k-4]);
					ans=min(ans,Min+f[k]+v[k-1]);
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}