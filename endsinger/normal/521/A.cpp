#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+7;
int n,c[N],mp[200],x,y;
char s[N];
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	mp['A']=0,mp['C']=1,mp['G']=2,mp['T']=3;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		c[mp[s[i]]]++;
	for(int i=0;i<4;i++)
	{
		if(c[i]>x)
		{
			x=c[i];
			y=1;
		}
		else if(c[i]==x)
			y++;
	}
	printf("%d\n",qp(y,n));
	return 0;
}