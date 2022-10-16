#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=5e5+5;//4194304
struct node
{
	int next,to;
	char v;
}e[xx];
int cnt;
int h[xx];
void add(int x,int y,char z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].v=z;
}
int n;
int size[xx];
int son[xx];
int dep[xx];
char v[xx];
void dfs(int x)
{
	size[x]=1;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		dep[e[i].to]=dep[x]+1;
		dfs(e[i].to);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxx)maxx=size[e[i].to],son[x]=e[i].to,v[x]=e[i].v;
	}
}
int now;
int ans[xx];
int maxd[4194304+21];
void clear(int x)
{
	maxd[now]=-1e9;
	for(int i=h[x];i;i=e[i].next)
	{
		now^=(1<<(e[i].v-'a'));
		clear(e[i].to);
		now^=(1<<(e[i].v-'a'));
	}
}
int res;
//void c(int x)
//{
//	char s[40];
//    itoa(x,s,2);
//    printf("%s\n",s);
//}
void addans(int x)
{
//	c(now);
//	cout<<x<<"res"<<res<<endl;
	res=max(res,dep[x]+maxd[now]);
//	cout<<x<<"res"<<res<<endl;
	for(int i=0;i<22;i++)res=max(res,dep[x]+maxd[now^(1<<i)]);
//	cout<<x<<"res"<<res<<endl;
	for(int i=h[x];i;i=e[i].next)
	{
		now^=(1<<(e[i].v-'a'));
		addans(e[i].to);
		now^=(1<<(e[i].v-'a'));
	}
}
void addbian(int x)
{
//	cout<<x<<" q "<<dep[x]<<" ";c(now);
	maxd[now]=max(maxd[now],dep[x]);
	for(int i=h[x];i;i=e[i].next)
	{
		now^=(1<<(e[i].v-'a'));
		addbian(e[i].to);
		now^=(1<<(e[i].v-'a'));
	}
}
void dfss(int x)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==son[x])continue;
		now^=(1<<(e[i].v-'a'));
		dfss(e[i].to);
		clear(e[i].to);res=0;
		now^=(1<<(e[i].v-'a'));
	}
	if(son[x])
	{
		now^=(1<<(v[x]-'a'));
		dfss(son[x]);
		now^=(1<<(v[x]-'a'));
	}
	res=0;
//	if(x==1)puts("-=-=-=-=-=-=-=-=-=-");
	maxd[now]=max(maxd[now],dep[x]);
	for(int i=h[x];i;i=e[i].next)
	if(e[i].to!=son[x])
	{
		now^=(1<<(e[i].v-'a'));
		addans(e[i].to);
		addbian(e[i].to);
		now^=(1<<(e[i].v-'a'));
	}
	for(int i=h[x];i;i=e[i].next)ans[x]=max(ans[x],ans[e[i].to]);
	res=max(res,maxd[now]+dep[x]);
	for(int i=0;i<22;i++)res=max(res,maxd[now^(1<<i)]+dep[x]);
//	if(x==2)c(now),puts("--------------------");
//	if(x==4)c(now),puts("--------------------");
//	if(x==10)c(now),puts("--------------------");
//	cout<<x<<" "<<dep[x]<<" ";c(now);
//	cout<<x<<"";
//	cout<<res<<"\n";
//	cout<<res<<" "<<x<<endl;
	ans[x]=max(ans[x],res-dep[x]-dep[x]);
}
int main(){
	memset(maxd,-0x3f,sizeof(maxd));
	n=read();
	for(int i=2;i<=n;i++)
	{
		int a=read();
		char c;while((c=getchar())>'z'||c<'a');
		add(a,i,c);
	}
	dfs(1);
	dfss(1);
//	puts("qweqeq");
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return 0;
}