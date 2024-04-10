#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 2000000000
#define ll long long
#define MAXN 200000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,k,ans;
int c[MAXN+5];
struct ed{
	int num,x;
}s[MAXN+5];
int getfa(int xx)
{
	if(s[xx].x==xx) return xx;
	s[xx].x=getfa(s[xx].x);
	return s[xx].x;
}

bool cmp(ed xx,ed yy)
{
	if(xx.x==yy.x) return c[xx.num]<c[yy.num];
	return xx.x<yy.x;
}

int main()
{
	n=read(),m=read(),k=read();ans=n;
	for(int i=1;i<=n;i++) c[i]=read(),s[i].x=s[i].num=i;
	for(int i=1;i<=m;i++)
	{
		int x=read();
		int y=read();
		x=getfa(x);y=getfa(y);
	    if(x!=y) s[x].x=y;
	}
	for(int i=1;i<=n;i++)
       s[i].x=getfa(i);
    sort(s+1,s+n+1,cmp);
    int precolor=-1,pren=-1,nown=0;
    int i=1,maxn=0;
    //for(int i=1;i<=n;i++)
    //   printf("%d c:%d pre:%d\n",i,s[i].x,c[s[i].num]);
    while(i<=n)
    {
		while(i<=n&&s[i].x==precolor)
		{
			while(i<=n&&s[i].x==precolor&&c[s[i].num]==pren)
			{
			//	printf("%d %d %d++++%d %d!!!\n",i,s[i].x,precolor,c[s[i].num],pren);
			   i++;nown++;
		    }
		    pren=c[s[i].num];
		    maxn=max(maxn,nown);
		    nown=0;
		}
	//	printf("c:%d  %d\n",precolor,maxn);
		ans-=maxn;
		precolor=s[i].x;
		maxn=1;
    }
    cout<<ans;
   // ans=0;
   // for(int i=1;i<=n;i++)
   //    if(getfa(i)!=i&&c[s[i].x]!=c[i]) ans++;
   // cout<<ans;
	return 0;
}