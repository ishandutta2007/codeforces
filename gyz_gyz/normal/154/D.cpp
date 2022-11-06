#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int x1,x2,x,a,b,u;
int main(){
	scanf("%d%d%d%d",&x1,&x2,&a,&b);
	if(x1+a<=x2&&x1+b>=x2){
		printf("FIRST\n%d\n",x2);return 0;
	}x=x2-x1;
	if(a<0&&b<0){
		u=1;a=-a;b=-b;x=-x;swap(a,b);
	}
	if(a<=0||x<0){
		printf("DRAW\n");return 0;
	}
	if(x%(a+b)==0)printf("SECOND\n");
	else{
		if(x%(a+b)<a||x%(a+b)>b){
			printf("DRAW\n");return 0;
		}
		printf("FIRST\n");
		if(u)printf("%d\n",x1-x%(a+b));
		else printf("%d\n",x1+x%(a+b));
	}
}