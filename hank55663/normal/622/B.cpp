#include<stdio.h>
main(){
	int h,m,ans;
	scanf("%d:%d",&h,&m);
	scanf("%d",&ans);
	m+=ans;
	h+=m/60;
	m%=60;
	h%=24;
	printf("%02d:%02d",h,m);
	return 0;
}