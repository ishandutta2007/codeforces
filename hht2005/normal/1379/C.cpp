#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
long long sum[N];
int main() {
	int T,n,m;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) {
			scanf("%d%d",a+i,b+i);
			c[i]=a[i];
		}
		sort(c+1,c+m+1);
		sum[m+1]=0;
		for(int i=m;i>=1;i--)sum[i]=sum[i+1]+c[i];
		long long Max=0;
		for(int i=1;i<=m;i++) {
			long long ans=0;
			int R=m-(n-1)+1;
			if(a[i]>=b[i])R--;
			else ans+=a[i];
			int t=max((int)(lower_bound(c+1,c+m+1,b[i])-c),R);
			ans+=sum[t];
			int A=n-(m-t+1);
			if(a[i]<b[i])A--;
			ans+=1ll*A*b[i];
			Max=max(Max,ans);
		}
		printf("%lld\n",Max);
	}
	return 0;
}