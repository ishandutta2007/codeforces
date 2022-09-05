#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b;
int n;
int bita[70],bitb[70],ans[70];
LL out()
{
	LL res=0;
	for(int i=0;i<70;i++)
		if(ans[i]==1)
			res|=1ll<<i;
	return res;
}
void calc()
{
	for(int i=0;i<70;i++)
	{
		bita[i]=a&1;
		bitb[i]=b&1;
		a>>=1;
		b>>=1;
	}
	memset(ans,0,sizeof(ans));
	for(int i=69;i>=0;i--)
		if(bita[i]!=bitb[i])
		{
			bool ok=true;
			for(int j=i-1;j>=0;j--)
			{
				ans[j]=1;
				ok&=bitb[j];
			}
			if(ok)
				ans[i]=1;
			printf("%I64d\n",out());
			return;
		}
		else
			ans[i]=bita[i];
	printf("%I64d\n",out());
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%I64d%I64d",&a,&b);
		calc();
	}
	return 0;
}