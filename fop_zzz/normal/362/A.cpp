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
char s[201];
int n,m,sx1,sy1,sx2,sy2;
int main()
{
	for(int T=read();T;T--)
	{
		sx1=sx2=sy1=sy2=0;
		For(i,1,8)
		{
			scanf("\n%s",s+1);
			int len=strlen(s+1);
			if(len==0)	break;
			For(j,1,len)	
				if(s[j]=='K')	if(sx1)	sx2=i,sy2=j;else	sx1=i,sy1=j;		
		}		
		if((abs(sx1-sx2)==4||abs(sx1-sx2)==0)&&(abs(sy1-sy2)==4||abs(sy1-sy2)==0))	puts("YES");else puts("NO");
	}
}