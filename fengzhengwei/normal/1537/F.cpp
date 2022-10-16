#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int a[xx],b[xx];
ll sum1,sum2;
int cr=1,col[xx];
void rs(int x,int y)
{
	col[x]=y;sum1+=y==1?a[x]:-a[x];sum2+=y==1?b[x]:-b[x];
	for(int i=h[x];i;i=e[i].next)if(!col[e[i].to])rs(e[i].to,3-y);else if(col[e[i].to]!=3-y)cr=0;
}
signed main(){
	int T=read();
	while(T--)
	{
		memset(e,0,sizeof(e[0])*(cnt+1));
		sum1=sum2=0;
		int n=read(),m=read();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++)col[i]=0;
		for(int i=1;i<=m;i++)
		{
			int a=read(),b=read();
			add(a,b),add(b,a);
		}
		cr=1;
		rs(1,1);
		if(cr)
		{
//			cout<<sum1<<" "<<sum2<<"\n";
			if(sum1==sum2)puts("YES");
			else puts("NO");
		}
		else if(!cr)
		{
			sum1=0;
			for(int i=1;i<=n;i++)sum1+=a[i];
			for(int i=1;i<=n;i++)sum1+=b[i];
			if(sum1&1)puts("NO");
			else puts("YES");
		}
	}
	return 0;
}