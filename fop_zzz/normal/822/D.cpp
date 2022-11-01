#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <vector>
#define ll long long
#define N 1020
#define lson x*2
#define rson x*2+1
#define mk make_pair
#define pa pair<int,int>
#define fir first
#define sec second
#define inf 1e9
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define maxn 2000005  
#define base 233  
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
bool bj[6000001];
ll pri[6000001],tot,to[6000001],t,L,R,mo=1e9+7,f[6000001];
inline void pre()
{
	For(i,2,R)	
	{
		if(!bj[i])	{pri[++tot]=i;f[i]=(ll)i*(i-1)/2;f[i]%=mo;}
		For(j,1,tot)
		{
			if(i*pri[j]>R)	break;
			bj[i*pri[j]]=1;to[i*pri[j]]=pri[j];
			if(i%pri[j]==0)	break;
		}
	}
}
int main()
{
	t=read();L=read();R=read();
	pre();
	f[1]=1;
	For(i,2,R)
		if(!f[i])	f[i]=f[to[i]]*(i/to[i])+f[i/to[i]],f[i]%=mo;
	ll v=1,ans=0;
	For(i,L,R)
	{
		ans+=f[i]*v,ans%=mo;	
		v*=t;v%=mo;
	}
	writeln(ans);
}