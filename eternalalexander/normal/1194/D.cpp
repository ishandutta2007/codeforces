#include <bits/stdc++.h>

int t,n,k;

int main() {
	scanf("%d",&t);
	while (t--){
		int res=0;
		scanf("%d%d",&n,&k);
		if (n==0) {printf("Bob\n");continue;}
		if (k%3==1||k%3==2) 
			res=(n%3!=0);
		else {
			int d=k/3-1;
			int loop=d*3+4;
			int now=n%loop;
		//	printf("%d %d\n",loop,now);
			if (now<=loop-4) res=(now%3!=0);
			else res=((now-(loop-4))%4!=0);
		}
		if (res==0) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}