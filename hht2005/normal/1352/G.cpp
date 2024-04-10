#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(n==1) {
			puts("1");
			continue;
		}
		if(n==2||n==3) {
			puts("-1");
			continue;
		}
		if(n==4) {
			puts("2 4 1 3");
			continue;
		}
		for(int i=1;i<=n;i+=2)
			printf("%d ",i);
		if(n&1) {
			printf("%d ",n-3);
			printf("%d ",n-1);
			for(int i=n-5;i>=1;i-=2)
				printf("%d ",i);
			puts("");
		} else {
			printf("%d ",n-4);
			printf("%d ",n);
			printf("%d ",n-2);
			for(int i=n-6;i>=1;i-=2)
				printf("%d ",i);
			puts("");
		}
	}
	return 0;
}