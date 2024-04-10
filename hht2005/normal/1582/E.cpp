#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=453;
int a[N];
long long Max[N][M];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		memset(Max[n+1],0,sizeof(Max[n+1]));
		Max[n+1][0]=1e18;
		int K=sqrt(2*(n+1))+1,ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=n;i>=1;i--) {
			long long sum=0;
			memcpy(Max[i],Max[i+1],sizeof(Max[i]));
			for(int k=1;k<=K&&k+i-1<=n;k++) {
				sum+=a[i+k-1];
				if(sum<Max[i+k][k-1]) {
					Max[i][k]=max(Max[i][k],sum);
					ans=max(ans,k);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}