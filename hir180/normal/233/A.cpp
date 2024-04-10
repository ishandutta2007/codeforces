#include <cstdio>
#include <algorithm>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('') */
int main(){
	int a=0,b=0,c=0,d=0,e=0,i,y=0,num=0,sum=0;
	int x[105];
	scanf("%d",&a);
	x[2]=1;
	x[1]=2;
	for(b=3;b<=a;b++){
		x[b]=a-b+3;
	}
	if(a%2==1){
		printf("-1\n");
		goto s;
	}
printf("%d",x[1]);
for(i=2;i<=a;i++){
	printf(" %d",x[i]);
}
	printf("\n");
	s:;
	return 0;
}