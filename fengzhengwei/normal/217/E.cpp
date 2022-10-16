#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=4e6+5;
char s[xx],ans[xx];
int lb(int x){return x&-x;}
int sum[xx],res; 
void add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;res+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
int ef(int x)
{
	//<=x-1 
	if(res<x)return -1;
	int nw=0,sm=0; 
	for(int i=22;i>=0;i--)
		if(nw+(1<<i)<xx&&sm+sum[nw+(1<<i)]<=x)nw+=(1<<i),sm+=sum[nw];
	return nw;
}
int gfir(int x)
{
	int a=ef(x-1);
	if(a==-1||(a+1)>=xx)return -1;
	return a+1;
}
struct pr{int x,y;};
pr stk[xx];
int top,n,q;
int l[xx],r[xx];
signed main(){
	scanf("%s",s+1);
	n=read(),q=read();
	for(int i=1;i<=n;i++)add(i,1);
	for(int i=q;i>=1;i--)l[i]=read(),r[i]=read();
//	while(q--)
	for(int i=1;i<=q;i++)
	{
//		int l=read(),r=read();
		#define l l[i]
		#define r r[i]
		int st=gfir(r+1),L;
		if(st==-1)continue;
		///fn 
		for(int j=l+1;j<=r;j+=2)
		{
			st=gfir(r+1),L=gfir(j);
			if(st==-1||L==-1)break;
			stk[++top]={L,st};
			add(st,-1);
		}
		for(int j=l;j<=r;j+=2)
		{
			st=gfir(r+1),L=gfir(j);
			if(st==-1||L==-1)break;
			stk[++top]={L,st};
			add(st,-1);
		}
	}
	int tt=0;
	for(int i=1;i<=n;i++)
		if(ask(i))add(i,-1),ans[i]=s[++tt];
//	for(int i=1;i<=top;i++)
//	{
//		cout<<stk[i].x<<" "<<stk[i].y<<"!\n";
//	}
	for(int i=top;i>=1;i--)ans[stk[i].y]=ans[stk[i].x];
	for(int i=1;i<=n;i++)cout<<ans[i];
	puts("");
	pc('1',1);
	return 0;
}