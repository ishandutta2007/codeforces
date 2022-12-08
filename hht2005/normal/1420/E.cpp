#include<bits/stdc++.h>
using namespace std;
int f[85][85][6405],p[85],ans[6405];
int main() {
	memset(f,0x3f,sizeof(f));
	memset(ans,0x3f,sizeof(ans));
	f[0][0][0]=0;
	int n,a,m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		if(a==1)p[++m]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m&&j<=i;j++)
			for(int k=abs(i-p[j]);k<=n*(n-1)/2;k++)
				for(int l=0;l<i;l++)
					f[i][j][k]=min(f[i][j][k],f[l][j-1][k-abs(i-p[j])]+(i-l-1)*(i-l-2)/2);
	if(!m)ans[0]=n*(n-1)/2;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n*(n-1)/2;j++)
			ans[j]=min(ans[j],f[i][m][j]+(n-i)*(n-i-1)/2);
	for(int i=0;i<=n*(n-1)/2;i++) {
		printf("%d ",(n-m)*(n-m-1)/2-ans[i]);
		ans[i+1]=min(ans[i+1],ans[i]);
	}
	puts("");
	return 0;
}