#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int T;
const int xx=5e5+5;
struct node{int next,to;}e[xx<<1];
int h[xx],cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
struct nod{int a,b;}s[xx];
int a[xx],b[xx],a_b[xx],b_a[xx],vis[xx];
void dfs(int x)
{
	if(vis[x])return;vis[x]=1;
	for(int i=h[x];i;i=e[i].next)dfs(e[i].to);
}
int n;
signed main(){
	T=read();
	while(T--)
	{
		memset(e,0,sizeof(e[0])*(cnt+1));
		cnt=0;
		n=read();
		memset(h,0,sizeof(h[0])*(n+n+1));
		for(int i=1;i<=n;i++)vis[i]=vis[i+n]=0;
		for(int i=1;i<=n;i++)
			s[i].a=a[i]=read();
		for(int i=1;i<=n;i++)
			s[i].b=b[i]=read();
			
//		cout<<s[i].a<<"QWEQE\n";
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
		{
			a_b[lower_bound(a+1,a+n+1,s[i].a)-a]=s[i].b;
//			cerr<<(lower_bound(a+1,a+n+1,s[i].a)-a)<<" "<<i<<" "<<s[i].a<<"QWEQE\n";
			b_a[lower_bound(b+1,b+n+1,s[i].b)-b]=s[i].a;
		}
		for(int i=1;i<=n;i++)a_b[i]=max(a_b[i],a_b[i-1]);
		for(int i=1;i<=n;i++)b_a[i]=max(b_a[i],b_a[i-1]);
		for(int i=1;i<=n;i++)
			add(lower_bound(b+1,b+n+1,a_b[i])-b+n,i);
//			,cerr<<i<<" "<<a_b[i]<<"QW\n";
		//bidn 
		for(int i=1;i<=n;i++)
			add(lower_bound(a+1,a+n+1,b_a[i])-a,i+n);
		dfs(n);
		dfs(n+n);
		for(int i=1;i<=n;i++)
		{
			if(vis[lower_bound(a+1,a+n+1,s[i].a)-a]||vis[lower_bound(b+1,b+n+1,s[i].b)-b+n])cout<<1;
			else cout<<0;
		}
		puts("");
	}
	pc('1',1);
	return 0;
}