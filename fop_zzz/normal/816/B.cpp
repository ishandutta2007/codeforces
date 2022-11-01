#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
using namespace std;
inline void read(int &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
int f[1000001];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int v)
{
	for(int i=x;i<=200000;i+=lowbit(i))
		f[i]++;
}
inline int get(int x)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i))
		sum+=f[i];
	return sum;
}
int n,k,m,x,y,bj[500001],v[500001];
int main()
{
	read(n);read(k);read(m);
	For(i,1,n)	read(x),read(y),bj[x]+=1,bj[y+1]-=1;
	For(i,1,200000)	v[i]=v[i-1]+bj[i];	
	For(i,1,200000)	if(v[i]>=k)	add(i,1);
	For(i,1,m)	
	{
		read(x);read(y);
		printf("%d\n",get(y)-get(x-1)); 
	}
}