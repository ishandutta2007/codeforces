#include<bits/stdc++.h>
using namespace std;
long long f[2010][2010],a[2010];
int main() {
	int n;
	scanf("%d",&n);
	memset(f,0xc0,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		for(int j=0;j<i;j++) {
			f[i][j]=max(f[i][j],f[i-1][j]);
			f[i][j+1]=max(f[i][j+1],f[i-1][j]+a[i]);
			if(f[i][j+1]<0)f[i][j+1]=-1e18;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		if(f[n][i]>=0)ans=i;
	printf("%d\n",ans);
	return 0;
}