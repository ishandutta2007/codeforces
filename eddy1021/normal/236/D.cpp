#include <stdio.h>
double pre,ans,tmp;
int n;
int main(){
	scanf("%d",&n); while( n-- ){
		scanf("%lf",&tmp); pre=pre*tmp;
		ans+=(pre*2)+tmp; pre+=tmp;
	}
	printf("%.15lf\n",ans); return 0;
}