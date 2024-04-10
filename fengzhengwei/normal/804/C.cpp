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
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
vector<int>v[xx];
int t[xx],col[xx];
void dfs(int x,int y)
{
	for(auto it:v[x])
		if(col[it])t[col[it]]=1;
	int l=1;
	for(auto it:v[x])
	{
		if(!col[it])
		{
//		cerr<<"it="<<it<<" "<<x<<" "<<l<<"!!\n";
			while(t[l])l++;
			col[it]=l;t[l]=1;
		}
	}
	for(auto it:v[x])
		if(col[it])t[col[it]]=0;
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x);
}
int main(){
	int n=read(),m=read();
	int mx=1,id=0;
	for(int i=1;i<=n;i++)
	{
		int s=read();
		if(s>=mx)mx=s,id=i;
		while(s--)v[i].push_back(read());
	}
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	cout<<mx<<"\n";
	dfs(id,0);
	for(int i=1;i<=m;i++)if(!col[i])col[i]=1;
	for(int i=1;i<=m;i++)cout<<col[i]<<" \n"[i==m];
	pc('1',1);
	return 0;
}