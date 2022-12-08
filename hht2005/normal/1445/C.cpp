#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,q;
	long long p;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%d",&p,&q);
		long long Max=p,P=p;
		for(int i=2;i*i<=q;i++) {
			if(q%i==0) {
				int c1=0,c2=0;
				while(q%i==0)q/=i,c1++;
				while(p%i==0)p/=i,c2++;
				long long ans=1;
				for(int j=1;j<=c2-c1+1;j++)ans*=i;
				Max=min(Max,ans);
			}
		}
		if(q!=1) {
			int c2=0;
			while(p%q==0)p/=q,c2++;
			long long ans=1;
			for(int j=1;j<=c2;j++)ans*=q;
			Max=min(Max,ans);
		}
		printf("%lld\n",P/Max);
	}
	return 0;
}