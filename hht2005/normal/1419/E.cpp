#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int p[maxn],f[maxn],d[maxn];
int gcd(int x,int y) {
	while(y^=x^=y^=x%=y);
	return x;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,x,cnt=0,tot=0,ans=0,T=0;
		scanf("%d",&n);
		x=n;
		for(int i=2;i*i<=x;i++) {
			if(x%i==0)p[++tot]=i;
			while(x%i==0)x/=i;
		}
		for(int i=1;i*i<=n;i++)
			if(n%i==0) {
				d[++T]=i;
				if(i*i!=n)d[++T]=n/i;
			}
		sort(d+1,d+T+1);
		if(x!=1)p[++tot]=x;
		f[++cnt]=p[1]*p[tot];
		f[++cnt]=p[tot];
		for(int j=3;j<=T&&d[j]*p[tot]<=n;j++)
			if(n%(p[tot]*d[j])==0)f[++cnt]=p[tot]*d[j];
		while(n%p[tot]==0)n/=p[tot];
		for(int i=tot-1;i>=1;i--) {
			for(int j=1;j<=T&&d[j]*p[i]<=n;j++)
				if(n%(p[i]*d[j])==0)f[++cnt]=p[i]*d[j];
			while(n%p[i]==0)n/=p[i];
		}
		for(int i=1;i<=cnt;i++)
			printf("%d ",f[i]);
		puts("");
		for(int i=1;i<cnt;i++)
			if(gcd(f[i],f[i+1])==1)ans++;
		if(gcd(f[cnt],f[1])==1)ans++;
		printf("%d\n",ans);
	}
	return 0;
}