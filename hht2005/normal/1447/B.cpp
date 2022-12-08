#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n,m;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		int sum=0,mi=1e9,cnt=0,a;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				scanf("%d",&a);
				sum+=abs(a);
				mi=min(mi,abs(a));
				if(a<0)cnt++;
			}
		if(cnt&1)printf("%d\n",sum-2*mi);
		else printf("%d\n",sum);
	}
	return 0;
}