#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100050
int a[N],n,s[N],A,B,sum;
int main() {
	scanf("%d%d%d",&n,&A,&B);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	int si=a[1]*A;
	sort(a+2,a+n+1);
	for(i=n;i>=2;i--) {
		if(1.0*si/sum>=B) {
			printf("%d\n",n-i); return 0;
		}
		sum-=a[i];
	}
	if(1.0*si/sum>=B) printf("%d\n",n-1);
	return 0;
}