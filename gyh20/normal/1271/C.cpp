#include<cstdio>
#include<iostream>
#define re register
using namespace std;
int a,b,c,d,x,y,n,xx,yy;
int main(){
scanf("%d%d%d",&n,&x,&y);
while(n--){
	scanf("%d%d",&xx,&yy);
	if(yy>y)++a;
	if(xx<x)++b;
	if(yy<y)++c;
	if(xx>x)++d;
}
int tmp=max(a,max(b,max(c,d)));
if(tmp==a){
	printf("%d\n",a);
	printf("%d %d",x,y+1);
}
else if(tmp==b){
	printf("%d\n",b);
	printf("%d %d",x-1,y);
}
else if(tmp==c){
	printf("%d\n",c);
	printf("%d %d",x,y-1);
}
else{
	printf("%d\n",d);
	printf("%d %d",x+1,y);
}
}