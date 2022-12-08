#include<bits/stdc++.h>
using namespace std;
long long c[10];
int main() {
	int T;
	long long x,y;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=6;i++)
			scanf("%lld",c+i);
		for(int i=1;i<=6;i++)
			for(int j=1;j<=6;j++) {
				int p=j-1,k=j+1,n=k+1;
				if(p<1)p=6;
				if(k>6)k=1;
				if(n>6)n%=6;
				c[j]=min(c[j],c[k]+c[p]);
				c[k]=min(c[k],c[j]+c[n]);
			}
		if(x<=0&&y>=0)printf("%lld\n",c[3]*-x+c[2]*y);
		else if(x>=0&&y<=0)printf("%lld\n",c[6]*x+c[5]*-y);
		else if(x<=0&&y<=0) {
			if(x<=y)printf("%lld\n",-y*c[4]+(y-x)*c[3]);
			else printf("%lld\n",-x*c[4]+(x-y)*c[5]);
		}
		else if(x>=0&&y>=0) {
			if(x<=y)printf("%lld\n",x*c[1]+(y-x)*c[2]);
			else printf("%lld\n",y*c[1]+(x-y)*c[6]);
		}
	}
	return 0;
}