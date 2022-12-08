#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int f[maxn][maxn];
char s[maxn],t[maxn];
int main() {
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			if(s[i]==t[j])f[i][j]=f[i-1][j-1]+2;
			f[i][j]=max(f[i][j],f[i-1][j-1]-2);
			f[i][j]=max(f[i][j],f[i-1][j]-1);
			f[i][j]=max(f[i][j],f[i][j-1]-1);
			ans=max(ans,f[i][j]);
		}
	printf("%d\n",ans);
	return 0;
}