#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 150
int a[N],n,k;
int main() {  
	scanf("%d%d",&n,&k);
	int i,x,y;
	for(i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		a[i]=x*60+y;
	}
	a[0]=0;
	if(a[1]>=k+1) {
		puts("0 0"); return 0;
	}
	for(i=2;i<=n;i++) {
		if(a[i]-a[i-1]>=k*2+2) {
			int t=a[i-1]+k+1;
			printf("%d %d\n",t/60,t%60); return 0;
		}
	}
	int t=a[n]+k+1;
	printf("%d %d\n",t/60,t%60);
	return 0;
}