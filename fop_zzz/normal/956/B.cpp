#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e16
#define db long double
#define pb push_back
using namespace std;
inline int read()
{
    int t=0,f=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-'0',c=getchar();
    return t*f;
}
inline void write(int x){if(x<0)	{putchar('-');write(-x);return;}if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
ll a[1000010],n,u,dd;
db ans;
int main(){
	n=read();u=read();dd=1;a[n+1]=1e15;
	For(i,1,n) 
		a[i]=read();
	ans=-inf;
	For(i,1,n) 
	{
		while (a[dd+1]-a[i]<=u)dd++;
		if (dd>i+1)	ans=max(ans,(db)(a[dd]-a[i+1])/(a[dd]-a[i]));
	}
	double sum=ans;
	if (sum!=-inf)	printf("%.20f",sum);
		else puts("-1");
}