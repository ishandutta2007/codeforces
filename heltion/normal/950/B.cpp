#include<cstdio> 
#include<algorithm>
using namespace std;
typedef long long LL;
LL read(){LL x;scanf("%lld",&x);return x;}
LL x[100010]={};
int main(){
	LL n=read(),m=read(),ans=0,y=0;
	for(int i=1;i<=n;i++)x[i]=read()+x[i-1];
	for(int i=1;i<=m;i++){
		y+=read();
		if(*lower_bound(x+1,x+n+1,y)==y)ans++;
	}
	printf("%lld",ans);
}