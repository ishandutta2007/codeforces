#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int a[N],f[N][N];
int main() {
	int n,ans=0;
	char opt[5];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",opt);
		if(opt[0]=='+')scanf("%d",a+i);
		else a[i]=-1;
	}
	for(int x=1;x<=n;x++) {
		if(a[x]==-1)continue;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=i;j++) {
				if(i==x)f[i][j]=f[i-1][j];
				else {
					if(a[i]==-1)f[i][j]=(f[i-1][j+1]+1ll*((j==0&&i<x)+1)*f[i-1][j])%mod;
					else if(a[i]<a[x]+(i<x))f[i][j]=(f[i-1][j]+(j!=0)*f[i-1][max(j-1,0)])%mod;
					else f[i][j]=2*f[i-1][j]%mod;
				}
			}
		}
		for(int i=0;i<=n;i++)ans=(ans+1ll*a[x]*f[n][i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}