#include<cstdio>
#include<algorithm>
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
	int v,w;
}a[N];
bool cmp(st m,st n){return m.v<n.v;}
int f[N],val[N],sum[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main()
{
	int n=read(),s=0,max=0,ans;
	for(int i=1;i<=n;++i)a[i].v=read(),f[i]=a[i].w=i;
	std::sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		int w=a[i].w;
		for(int j=w-1;j<=w+1;j+=2)
		{
			int t=find(j);
			if(val[t])
			{
				if(!--sum[val[t]])--s;
				val[f[t]=w]+=val[t];
			}
		}
		if(!sum[++val[w]]++)++s;
		if(a[i].v!=a[i+1].v&&s==1&&sum[val[w]]>max)ans=a[i].v+1,max=sum[val[w]];
	}
	write(ans);
	return 0;
}