#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio> 
#include<algorithm>
#include<ctime>
#include<map>
#define ll long long 
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
using namespace std;
inline ll read()
{
    ll t=0,f=1;char tmp=getchar();
    while(tmp<'0'||tmp>'9')   {if(tmp=='-')	f=-1;tmp=getchar();}
    while(tmp>='0'&&tmp<='9') t=t*10+tmp-48,tmp=getchar();
    return t*f;
}
ll n,k,a[20001],tot;
inline bool cmp(ll x,ll y){return x>y;}
int main()	
{
	n=read();k=read();
	For(i,1,n)	a[i]=read();
	sort(a+1,a+n+1,cmp);
	For(i,0,n-1)
	{
		tot=i;
		For(j,i+1,n)
		{
			printf("%d ",tot+1);k--;
			For(K,1,i)	printf("%d ",a[K]);printf("%d\n",a[j]);
			if(k==0)	return 0;
		}
	}
}