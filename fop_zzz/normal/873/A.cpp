#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define eps 1e-5
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define maxn 1000000
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n,k,t,a[2001],ans;
int main()
{
	n=read();k=read();t=read();
	For(i,1,n)	a[i]=read();
	int tot=0;
	Dow(i,1,n)
	{
		tot++;
		if(tot<=k)	ans+=t;else ans+=a[i];
	}
	cout<<ans<<endl;
}