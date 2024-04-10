#include<cstdio>
#define re register
using namespace std;
int n,ans[100002],k;
inline void check(re int x){
	if(x<0)return;
	re int sum=x,xx=x;
	while(x)sum+=x%10,x/=10;
	if(sum==n)ans[++k]=xx;
}
int main(){
	scanf("%d",&n);
	for(re int i=n-100;i<=n;++i)check(i);
	printf("%d\n",k);
	for(re int i=1;i<=k;++i)printf("%d ",ans[i]);
}