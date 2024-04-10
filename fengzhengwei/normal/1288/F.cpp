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
const int xx=1e5+5;
struct node{int next,to,v,s;}e[xx<<1];
int cnt=1,h[xx],cur[xx],d[xx],v[xx],ts[xx],now,s,t,tt;
void add(int x,int y,int a,int b){/*cout<<x<<" "<<y<<" "<<a<<" dd "<<b<<"#$%\n";*/cnt++;e[cnt]={h[x],y,a,b};h[x]=cnt;}
void ad(int x,int y,int a,int b){add(x,y,a,b),add(y,x,0,-b);}
void spfa()
{
	for(int i=1;i<=tt;i++)v[i]=0,d[i]=1e9,cur[i]=h[i];
	queue<int>q;d[t]=0,v[t]=1,q.push(t);
	while(!q.empty())
	{
		int x=q.front();q.pop();v[x]=0;
		for(int i=h[x];i;i=e[i].next)
		{
//		cout<<x<<" "<<d[x]<<" "<<e[i].to<<"!!\n";
			if(e[i^1].v&&d[e[i].to]>d[x]+e[i^1].s)
			{
				d[e[i].to]=d[x]+e[i^1].s;
				if(!v[e[i].to])v[e[i].to]=1,q.push(e[i].to);
			}
		}
	}
}
ll cost;
int dfs(int x,int mx)
{
//	cout<<x<<" "<<mx<<" "<<now<<" "<<d[x]<<"!! \n";
	if(x==t)
	{
		if(d[s]>0)cost-=1ll*d[s]*mx;
//		cout<<x<<" "<<d[s]<<" "<<mx<<"!\n";
		// 
		return mx;
	}
	int res=mx;v[x]=1,ts[x]=now;
	for(int &i=cur[x];i;i=e[i].next)
	{
		if(e[i].v&&!v[e[i].to]&&d[e[i].to]+e[i].s==d[x])
		{
			int a=dfs(e[i].to,min(res,e[i].v));
			res-=a,cost+=1ll*a*e[i].s,e[i].v-=a,e[i^1].v+=a;
			if(!res)return v[x]=0,mx-res;
		}
	}
	return v[x]=0,mx-res;
}
bool cd()
{
	int mn=2e9;
	for(int x=1;x<=tt;x++)
	{
		if(ts[x]!=now)continue;
		for(int i=h[x];i;i=e[i].next)if(e[i].v&&ts[e[i].to]!=now)mn=min(mn,d[e[i].to]+e[i].s-d[x]);
	}
//	cout<<mn<<"!!\n";
	if(mn==2e9)return 0;
	for(int i=1;i<=tt;i++)
	{
		cur[i]=h[i];
		if(ts[i]==now)d[i]+=mn;
	}
	return 1;
}
int go()
{
	spfa();
	int ans=0;
//	cout<<d[s]<<"!sdfg !\n";
	if(d[s]<0)++now,ans+=dfs(s,1e9);
	while(cd()&&d[s]<0)++now,ans+=dfs(s,1e9);//0 
//	cout<<d[s]<<"\n";
//	for(int i=1;i<=tt;i++)cout<<ts[i]<<" "<<now<<"!\n";
//	cout<<cd()<<"!!\n";
//	cout<<d[s]<<"\n";
//	spfa();
//	cout<<d[s]<<"!!\n";
	return ans;
}
const int inf=1e9;
int n1,n2,m,idu[xx],idd[xx],r,b;
char c1[xx],c2[xx];
int id[xx],ids[xx];
int main(){
	n1=read(),n2=read(),m=read();r=read(),b=read();
	scanf("%s",c1+1),scanf("%s",c2+1);
	s=++tt,t=++tt;
	int num=0;
	for(int i=1;i<=n1;i++)
	{
//		puts("Fgd");
		idu[i]=++tt;
		if(c1[i]=='R')ad(s,idu[i],1,-inf),ad(s,idu[i],inf,0),num++;
		if(c1[i]=='B')ad(idu[i],t,1,-inf),ad(idu[i],t,inf,0),num++;
		if(c1[i]=='U')ad(s,idu[i],inf,0),ad(idu[i],t,inf,0);
	}
	for(int i=1;i<=n2;i++)
	{
		idd[i]=++tt;
		if(c2[i]=='R')ad(idd[i],t,1,-inf),ad(idd[i],t,inf,0),num++;
		if(c2[i]=='B')ad(s,idd[i],1,-inf),ad(s,idd[i],inf,0),num++;
		if(c2[i]=='U')ad(s,idd[i],inf,0),ad(idd[i],t,inf,0);
	}
	// 
	for(int i=1;i<=m;i++)
	{
		int a=read(),B=read();
		id[i]=cnt+1;
		// 
		ad(idu[a],idd[B],1,r);
		ids[i]=cnt+1;
		ad(idd[B],idu[a],1,b);
	}
	go();
//	cout<<go()<<"!!\n";
//	cout<<cost<<" "<<r<<" "<<b<<"\n";
	if((-cost+10000000)/inf!=num)puts("-1"),exit(0);
	cout<<cost+1ll*inf*num<<"\n";
	for(int i=1;i<=m;i++)
	{
		if(e[id[i]].v==0)putchar('R');
		else if(e[ids[i]].v==0)putchar('B');
		else putchar('U');
	}
	puts("");
	
	pc('1',1);
	return 0;
}
/*
3 5 7 1 1
BUB
BUBRU
3 1
3 1
1 4
1 1
1 3
3 3
3 3

4 4 5 95 69
URUU
BURR
2 2
4 4
1 3
1 2
4 1
*/