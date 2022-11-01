#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio> 
#include<algorithm>
#include<set>
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
int n,m,a[20001];
int main()
{
	n=read();m=read();
	For(i,1,m)	a[i]=read();
	sort(a+1,a+m+1);
	For(i,1,m-2)	if(a[i]+1==a[i+1]&&a[i+1]+1==a[i+2])	{puts("NO");return 0;}
	if(a[1]==1||a[m]==n)	return puts("NO"),0;
	puts("YES");
}