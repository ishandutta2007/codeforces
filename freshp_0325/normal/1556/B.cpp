#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[100005];
LL Abs(LL x){return x>0?x:-x;}
void Solve()
{
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]),a[i]=(a[i]&1);
	LL p=0,q=0;
	for(LL i=1;i<=n;++i)	if(a[i])	++p;else	++q;
	LL ans=0;
	if(Abs(p-q)>1)
	{
		puts("-1");
		return ;
	}
	if(n&1)
	{
		int st=int(p>q);
		LL cnt=-1;
		for(LL i=1;i<=n;++i)
		{
			if(a[i]==st)
			{
				cnt+=2;
				ans+=Abs(i-cnt);
			}
		}
	}
	else
	{
		LL st1=0,st2=0;
		LL cnt;
		cnt=-1;
		for(LL i=1;i<=n;++i)
		{
			if(a[i])
			{
				cnt+=2;
				st1+=Abs(i-cnt);
			}
		}
		cnt=-1;
		for(LL i=1;i<=n;++i)
		{
			if(!a[i])
			{
				cnt+=2;
				st2+=Abs(i-cnt);
			}
		}
		ans=min(st1,st2);
	}
	printf("%lld\n",ans);
}
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)	Solve();
	return 0;
}