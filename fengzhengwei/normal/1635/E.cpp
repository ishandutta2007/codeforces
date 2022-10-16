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
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=5e5+5,mod=1e9+7;
int n,m;
int fa[xx],sum[xx];
//10 
int find(int x)
{
	if(fa[x]==x)return x;
	int y=fa[x];
	find(y);
	sum[x]=sum[x]^sum[y];
	fa[x]=fa[y];
	return fa[x];
}
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx],rd[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt]={h[x],y};
	h[x]=cnt;
	rd[y]++;
}
struct No
{
	int a,b,c;
};
int Op[xx];
int An[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=i,sum[i]=0;
	vector<No>v;
	for(int i=1;i<=m;i++)
	{
		int op=read(),a=read(),b=read();
		v.push_back({op,a,b});
		find(a),find(b);
		if(fa[a]==fa[b])
		{
			if(sum[a]^sum[b])continue;
			puts("NO");
			exit(0);
		}
		sum[fa[a]]=1^sum[a];
		fa[fa[a]]=b;
	}
	for(int i=1;i<=n;i++)if(fa[i]==i)Op[i]=0;// 
	for(int i=1;i<=n;i++)
	{
		find(i);
		Op[i]=Op[fa[i]]^sum[i];
	}
	for(auto it:v)
	{
		if(it.a==1)
		{
			if(Op[it.b])add(it.c,it.b);
			else add(it.b,it.c);
		}
		else 
		{
			if(Op[it.b])add(it.b,it.c);
			else add(it.c,it.b);
		}
	}
	vector<int>ans;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!rd[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		ans.push_back(x);
		q.pop();
		for(int i=h[x];i;i=e[i].next)
		{
			if(!(--rd[e[i].to]))
				q.push(e[i].to);
		}
	}
	if(ans.size()!=n)puts("NO"),
			exit(0);
	int tt=0;
	for(auto it:ans)
	{
		An[it]=++tt;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(Op[i]==0)
			cout<<"L ";
		else cout<<"R ";
		cout<<An[i]<<"\n";
	}
	pc('1',1);
	return 0;
}