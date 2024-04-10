#include <stdio.h>
int n;
double sum , tmp , ans;
int main(){
	scanf("%d",&n);
	for( int div = 1 ; div <= n ; div ++ ){
		scanf("%lf",&tmp); sum += tmp;
		if( sum/div > ans ) ans = sum/div;
	}
	printf("%.20lf\n",ans);
}