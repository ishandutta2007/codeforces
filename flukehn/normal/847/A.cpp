#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 110
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
struct zgz
{
	int next,to;
}a[N],b[N];
int head[N],head2[N],cnt=1,cnt2=1;
int n,hd,tl;
int l[N],r[N];
void add(int f,int t)
{
	r[f]=t,l[t]=f;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read();
		if(!hd&&!l[i])hd=i;
	}
	int now=hd;
	while(r[now])now=r[now];
	tl=now;
	for(int i=1;i<=n;i++)
	{
	
		if(!r[i]&&tl!=i)
		{
			now=i;
			while(l[now])now=l[now];
			add(tl,now);
			tl=i;
		}
		if(!l[i]&&hd!=i)
		{	
			now=i;
			while(r[now])now=r[now];
			add(now,hd);
			hd=i;
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d %d\n",l[i],r[i]);
}