#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long f[maxn][2],a[maxn];
int main() {
	int n;
	long long r1,r2,r3,d;
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	r1=min(r1,r3);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	memset(f,0x3f,sizeof(f));
	f[1][0]=a[1]*r1+r3;
	f[1][1]=min(r2,(a[1]+1)*r1);
	for(int i=2;i<=n;i++) {
		f[i][0]=f[i-1][0]+d+a[i]*r1+r3;
		f[i][0]=min(f[i][0],f[i-1][1]+min(r2,(a[i]+1)*r1)+2*r1+3*d);
		f[i][0]=min(f[i][0],f[i-1][1]+(a[i]+1)*r1+r3+3*d);
		f[i][1]=f[i-1][0]+d+min((a[i]+1)*r1,r2);
		f[i][1]=min(f[i][1],f[i-1][1]+3*d+r1+min((a[i]+1)*r1,r2));
	}
	printf("%lld\n",min(f[n][0],f[n-1][1]+2*d+r1*(a[n]+1)+r3));
	return 0;
}