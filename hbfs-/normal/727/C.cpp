#include <iostream>
#include <cstdio>

#define N 10050

using namespace std;

int n,nex[N],a[N],x[N],ans;

int main() {
	scanf("%d",&n);
	if (n%2 == 1) {
		for (int i=1;i<=n;i++) i==n?nex[i] = 1 : nex[i] = i+1;
		for (int i=1;i<=n;i++) {
			printf("? %d %d\n",i,nex[i]);
			fflush(stdout);
			scanf("%d",&x[i]);
		}
		
		for (int i=n;i>=1;i--) 
			if ((n-i) % 2 == 0)
				ans += x[i];
			else
				ans -= x[i];
		a[1] = ans / 2;
		for (int i=2;i<=n;i++) a[i] = x[i-1] - a[i-1];
		
		
		
		
	} else {
		for (int i=2;i<=n;i++) {
			printf("? 1 %d\n",i);
			fflush(stdout);
			scanf("%d",&x[i-1]);
		}
		printf("? 2 3\n");
		fflush(stdout);
		scanf("%d",&x[n]);
		a[2] = ( x[1] - x[2] + x[n] ) / 2;
		a[3] = x[n] - a[2];
		a[1] = x[1] - a[2];
		for (int i=4;i<=n;i++) a[i] = x[i-1] - a[1];
		
		
	}
	printf("! ");
		for (int i=1;i<=n;i++) printf("%d%c",a[i],i == n ? '\n' : ' ');
	return 0;
}