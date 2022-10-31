#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 300050
struct A {
	int c,id;
}a[N];
bool cmp(const A &x,const A &y){return x.c<y.c;}
int n,x1,x2,len[N],val[N],mn;
int main() {
	scanf("%d%d%d",&n,&x1,&x2);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&a[i].c),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) {
		len[i]=(int)ceil(1.0*x2/a[i].c);
		val[i]=len[i]+i;
	}
	val[0]=1000000000;
	for(i=1;i<=n;i++) {
		int need=(int)ceil(1.0*x1/a[i].c);
		if(i+need-1<=n) {
			int tail=i+need-1;
			if(tail<n&&n-tail>=len[tail+1]) {
				printf("Yes\n%d %d\n",need,n-tail);
				for(j=i;j<=tail;j++) printf("%d ",a[j].id); puts("");
				for(j=tail+1;j<=n;j++) printf("%d ",a[j].id); puts("");
				return 0;
			}
			if(i+n-tail>=val[mn]) {
				printf("Yes\n%d %d\n",need,i-mn+n-tail);
				for(j=i;j<=tail;j++) printf("%d ",a[j].id); puts("");
				for(j=mn;j<i;j++) printf("%d ",a[j].id);
				for(j=tail+1;j<=n;j++) printf("%d ",a[j].id); puts("");
				return 0;
			}
		}
		if(val[i]<val[mn]) mn=i;
	}
	puts("No");
	return 0;
}