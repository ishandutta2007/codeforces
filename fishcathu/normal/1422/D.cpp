#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(!(c&16));
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
struct st
{
	int first,second;
	bool operator<(const st m)const
	{
		return first<m.first;
	}
}a[N],b[N];
int to[N][5],val[N][5],dis[N],dui[N],fui[N];
void ad(int u,int v,int va,int i){to[u][i]=v,val[u][i]=va;}
int main()
{
    read();
    int n=read(),s=1;
    for(int i=1;i<=n+1;++i)a[i].second=b[i].second=i;
	a[n+1].first=read(),b[n+1].first=read();
	int t1=read(),t2=read();
    for(int i=1;i<=n;++i)a[i].first=read(),b[i].first=read();
	for(int i=1;i<=n+1;++i)ad(i,n+2,abs(a[i].first-t1)+abs(b[i].first-t2),0);
	sort(a+1,a+2+n),sort(b+1,b+2+n),memset(dis,0x7f,sizeof dis),dis[0]=dis[n+1]=0;
	for(int i=1;i<=n;++i)ad(a[i].second,a[i+1].second,a[i+1].first-a[i].first,1),ad(b[i].second,b[i+1].second,b[i+1].first-b[i].first,2),ad(a[i+1].second,a[i].second,a[i+1].first-a[i].first,3),ad(b[i+1].second,b[i].second,b[i+1].first-b[i].first,4);
	to[a[1].second][3]=to[b[1].second][4]=to[a[n+1].second][1]=to[b[n+1].second][2]=n+1;
	dui[1]=n+1;
	while(dui[1]!=n+2)
	{
		int u=dui[1],t=dui[s--],i=1;
		while(i<<1<=s)
		{
			int son=i<<1==s||dis[dui[i<<1]]<dis[dui[i<<1|1]]?i<<1:i<<1|1;
			if(dis[t]>dis[dui[son]])fui[dui[i]=dui[son]]=i,i=son;
			else break;
		}
		fui[dui[i]=t]=i;
		for(int j=5;j--;)
		{
			int v=to[u][j];
			if(dis[u]+val[u][j]<dis[v])
			{
				dis[v]=dis[u]+val[u][j];
				if(!fui[v])fui[v]=++s;
				i=fui[v];
				while(dis[v]<dis[dui[i>>1]])fui[dui[i]=dui[i>>1]]=i,i>>=1;
				fui[dui[i]=v]=i;
			}
		}
	}
	write(dis[n+2]);
	return 0;
}