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
    while(tmp<'0'||tmp>'9')   {if(tmp='-')	f=-1;tmp=getchar();}
    while(tmp>='0'&&tmp<='9') t=t*10+tmp-48,tmp=getchar();
    return t*f;
}
int n,sum;
int main()	
{
	n=read();
	For(i,1,n)	sum+=read();
	if(sum%n==0)	cout<<n<<endl;else cout<<n-1<<endl;
}