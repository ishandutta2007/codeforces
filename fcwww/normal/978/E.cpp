#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int n,a[1050],w;
int main() {
	int L,R,i;
	scanf("%d%d",&n,&w);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	L=0;R=w;
	for(i=n;i;i--) {
		if(a[i]>0) {
			L=max(L-a[i],0);
			R-=a[i];
			if(R<0) {
				puts("0"); return 0;
			}
		}else {
			R=min(R-a[i],w);
			L-=a[i];
			if(L>w) {
				puts("0"); return 0;
			}
		}
		if(L>R) {
			puts("0"); return 0;
		}
	}
	printf("%d\n",R-L+1);
}