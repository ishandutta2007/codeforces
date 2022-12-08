#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int w[maxn],p[maxn];
int cmp(int a,int b) {
	return w[a]<w[b];
}
int main() {
	int T,n;
	long long W,sum;
	scanf("%d",&T);
	while(T--) {
		sum=0;
		scanf("%d%lld",&n,&W);
		for(int i=1;i<=n;i++)
			scanf("%d",w+i),p[i]=i;
		sort(p+1,p+n+1,cmp);
		sort(w+1,w+n+1);
		int fl=0,cnt=0;
		for(int i=n;i>=1&&!fl;i--) {
			if(sum+w[i]>W)continue;
			if(sum+w[i]>=W/2+W%2)fl=1;
			sum+=w[i];
			cnt++;
		}
		if(!fl) {
			puts("-1");
			continue;
		}
		printf("%d\n",cnt);
		sum=0;
		for(int i=n;i>=1;i--) {
			if(sum+w[i]>W)continue;
			printf("%d ",p[i]);
			if(sum+w[i]>=W/2+W%2)break;
			sum+=w[i];
		}
		puts("");
	}
	return 0;
}