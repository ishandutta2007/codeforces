#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int a[2001],cnt[2001][3],ans,n;
int main()
{
	n=read();
	For(i,1,n)	a[i]=read(),cnt[i][0]=cnt[i-1][0]+(a[i]==0);
	Dow(i,1,n)	cnt[i][1]=cnt[i+1][1]+(a[i]==1);
	For(i,0,n)
		ans=max(ans,cnt[i][0]+cnt[i+1][1]);
	cout<<ans<<endl;
}