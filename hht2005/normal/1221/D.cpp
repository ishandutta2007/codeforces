#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long f[3][2];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,la,a,b,t=1;
		la=-3;
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) {
			scanf("%d%d",&a,&b);
			for(int j=0;j<3;j++) {
				f[j][t]=5e18;
				for(int k=0;k<3;k++)
					if(la+k!=a+j)
						f[j][t]=min(f[j][t],f[k][t^1]+b*j);
			}
			la=a;
			t^=1;
		}
		printf("%lld\n",min(f[0][t^1],min(f[1][t^1],f[2][t^1])));
	}
	return 0;
}