#include<bits/stdc++.h>
using namespace std;
long long P[20];
int p[20],f[20];
void kt(long long x,int n) {
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) {
		int t=x/P[n-i]+1,k=0;
		for(int j=1;j<=n;j++)
			if(!f[j]&&++k==t) {
				k=j;
				break;
			}
		f[p[i]=k]=1;
		x%=P[n-i];
	}
}
int main() {
	P[0]=1;
	for(int i=1;i<=15;i++)P[i]=P[i-1]*i;
	int n,q,opt,l,r;
	long long s=0;
	scanf("%d%d",&n,&q);
	kt(0,15);
	while(q--) {
		scanf("%d%d",&opt,&l);
		if(opt==1) {
			scanf("%d",&r);
			long long sum=0;
			for(int i=max(1,l-n+15);i<=r-n+15;i++)sum+=p[i]+n-15;
			if(r>n-15)r=n-15;
			if(l>r)l=r+1;
			printf("%lld\n",sum+1ll*(l+r)*(r-l+1)/2);
		} else if(opt==2) {
			s+=l;
			kt(s,15);
		}
	}
	return 0;
}