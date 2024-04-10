#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
long long a,b,X1,Y1,X2,Y2,x1,y1,x2,y2,tt;
long long abs(long long x){
	if(x<0)return -x;else return x;
}
long long max(long long x,long long y){
	if(x>y)return x;else return y;
}
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&x1,&y1,&x2,&y2);
	tt=4000000000ll/a/b/2+1;tt*=a*b*2;x1+=tt;x2+=tt;
	X1=(x1+y1)/a/2;Y1=(x1-y1)/b/2;
	X2=(x2+y2)/a/2;Y2=(x2-y2)/b/2;
	printf("%I64d\n",max(abs(X1-X2),abs(Y1-Y2)));
}