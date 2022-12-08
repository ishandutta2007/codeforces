#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n,m,k,a;
	scanf("%d",&T);
	while(T--) {
		int f=0;
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=m;i++) {
			scanf("%d",&a);
			if(a-i>=k/2&&n-a-m+i>=k/2)
				f=1;
		}
		if((n-m)%(k-1))f=0;
		puts(f?"YES":"NO");
	}
	return 0;
}