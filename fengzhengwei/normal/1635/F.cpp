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
const int xx=3e5+5;
int n,m;
struct nod{int x,w;}e[xx];
int stk[xx];
struct szsz
{
	ll sum[xx];
	int lb(int x){return x&-x;}
	//min 
	//min 
	void add(int x,ll y){x=n-x+1;for(;x<=n;x+=lb(x))sum[x]=min(sum[x],y);}
	ll ask(int x){ll ans=8e18;x=n-x+1;for(;x;x-=lb(x))ans=min(ans,sum[x]);return ans;}
}s;
vector<int>L[xx];
vector<pair<int,int> >v[xx];
ll get(int i,int j){return 1ll*(e[i].w+e[j].w)*abs(e[i].x-e[j].x);}
ll ans[xx];
int main(){
	memset(s.sum,0x3f,sizeof(s));
	n=read(),m=read();
	for(int i=1;i<=n;i++)e[i].x=read(),e[i].w=read();
	int top=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&e[i].w<e[stk[top]].w)top--;
		if(top)L[i].push_back(stk[top]);
		stk[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--)
	{
		while(top&&e[i].w<e[stk[top]].w)top--;
		if(top)L[stk[top]].push_back(i);
		stk[++top]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		v[r].push_back(make_pair(l,i));
	}
	for(int i=1;i<=n;i++)
	{
		for(auto it:L[i])s.add(it,get(it,i));
		for(auto it:v[i])ans[it.second]=s.ask(it.first);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}