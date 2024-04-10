#include<stdio.h>
int n,m;
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;;i++){
		if(i/2>=n&&i/3>=m&&i/2+i/3-i/6>=n+m)break;
	}
	printf("%d",i);
	return 0;
}