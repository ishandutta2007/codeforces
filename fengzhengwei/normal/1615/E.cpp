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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
int n,m,a=0;
void dfs(int x,int y)
{
	int vs=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		vs=0;
		dfs(e[i].to,x);
	}
	a+=vs;
}
int son[xx],dep[xx],md[xx];
int top[xx],bot[xx];
int f[xx];
void dfss(int x,int y)
{
	f[x]=y;
	dep[x]=dep[y]+1;md[x]=dep[x];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfss(e[i].to,x);
		if(md[x]<md[e[i].to])son[x]=e[i].to,md[x]=md[e[i].to];
	}
}
void Dfs(int x,int y)
{
	top[x]=y;
	bot[top[x]]=x;
	if(!son[x])return;
	Dfs(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		Dfs(e[i].to,e[i].to);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);
	if(m>=a)
	{
		ll num=min(m,n/2);
//		puts("Qweasdf");
		cout<<(n-num)*num<<"\n";
		exit(0);
	}
	//ban 
	dfss(1,0);
	Dfs(1,1);
	multiset<int>s;
	for(int i=1;i<=n;i++)
		if(top[i]==i)s.insert(dep[bot[i]]-dep[i]+1);
	int ans=0;
	int o=m;
	while(m--)
	{
//		cout<<(*--s.end())<<"QWEQ\n";
		ans+=*--s.end();
		s.erase(--s.end());
	}
	m=o;
	int rem=n-ans;// 
//	cout<<ans<<" "<<rem<<"\n";
//	if(rem<=m)
//		cout<<1ll*(n-rem-m)*(m-rem)<<"\n";
//	else 
//	{
		ll mn=1e18;
		for(int j=0;j<=rem;j++)
		{
			mn=min(mn,1ll*(n-j-m)*(m-j));
//			cout<<n<<" "<<j<<" "<<m<<"\n";
		}
		cout<<mn<<"\n";
//	}
	pc('1',1);
	return 0;
}