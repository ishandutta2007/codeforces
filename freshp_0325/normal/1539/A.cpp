#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void Solve()
{
	LL n,x,t;
	scanf("%lld %lld %lld",&n,&x,&t);
	t/=x;
	x=1;
	if(t==0)
	{
		puts("0");
		return ;
	}
	LL ans=0;
	LL st=min(n-1,t);
	ans+=(n-st)*st;
	ans+=(st-1)*st/2;
	printf("%lld\n",ans);
}
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)	Solve();
	return 0;
}