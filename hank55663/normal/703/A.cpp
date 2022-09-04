#include<stdio.h>
main(){
	int n;
	scanf("%d",&n);
	int a=0,b=0;
	for(int i=0;i<n;i++){
		int c,d;
		scanf("%d %d",&c,&d);
		if(c<d)
		b++;
		if(c>d)
		a++;
	}
	if(a>b)
	printf("Mishka\n");
	else if(a<b)
	printf("Chris\n");
	else
	printf("Friendship is magic!^^\n");
}