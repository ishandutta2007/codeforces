#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
ll mi;
ll getgcd(int x,int y)
{
	if(x<y) swap(x,y);
	if(!y) return x;
	return getgcd(y,x%y);
}
ll getlcm(int x,int y)
{
	return 1ll*x*y/getgcd(x,y);
}
void gets(int i)
{
	int y1=n%i;
	int tmp=(i-y1)%i;
	ll tmpmi=getlcm(n+tmp,m+tmp);
	if(tmpmi<mi) mi=tmpmi,ans=tmp;
}
int main()
{
	scanf("%d%d",&n,&m);
	int x=abs(n-m);
	if(!x) puts("0");
	else
	{
		ans=0,mi=getlcm(n,m);
		for(int i=1;i<=sqrt(x);i++)
		{
			if(x%i==0)
			{
				gets(i);
				gets(x/i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}