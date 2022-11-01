#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio> 
#include<algorithm>
#include<ctime>
#define ll long long 
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
using namespace std;
inline ll read()
{
    ll t=0,f=1;char tmp=getchar();
    while(tmp<'0'||tmp>'9')   {tmp=getchar();}
    while(tmp>='0'&&tmp<='9') t=t*10+tmp-48,tmp=getchar();
    return t*f;
}
int n,a[20001],b[2001];
int main()
{
	srand(time(0));
	n=read();
	For(T,1,10000)
	{
		For(i,1,n)	a[i]=rand()%100+1,b[i]=a[i];
		For(i,1,n-1)
			For(j,i,n-1)
				if(a[j]>a[j+1])	swap(a[j],a[j+1]);	
		For(i,1,n-1)	
		if(a[i]>a[i+1])	
		{
			For(j,1,n)	printf("%d ",b[j]);
			return 0;
		}
	}	
	puts("-1");
}