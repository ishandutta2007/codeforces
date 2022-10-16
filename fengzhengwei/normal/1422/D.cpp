#include<bits/stdc++.h>
#define ll long long
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
const int xx=1e5+5;
int n,m;
struct pr{int x,y;bool operator<(const pr&w)const{return x==w.x?y<w.y:x<w.x;}void in(){x=read(),y=read();}}s,t,E[xx];
struct nod{int next,to,v;}e[xx<<3];
int cnt,h[xx];
void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
void ad(int x,int y,int z){add(x,y,z),add(y,x,z);}
struct no
{
	int x,v;
	bool operator<(const no&w)const{return v>w.v;}
};
priority_queue<no>q;
set<pr>s1,s2;
set<pr>::iterator pre(set<pr>::iterator it){return --it;}
void Ad(set<pr>&s)
{
	for(auto it=s.begin();it!=s.end();++it)
		if(it!=s.begin())ad(pre(it)->y,it->y,((it->x)-(pre(it)->x)));
}
int f[xx],vis[xx];
int main(){
	n=read(),m=read();
	s.in(),t.in();
	s1.insert({s.x,0}),s2.insert({s.y,0});
	for(int i=1;i<=m;i++)E[i].in(),s1.insert({E[i].x,i}),s2.insert({E[i].y,i});
	E[0]=s;
	Ad(s1),Ad(s2);
	memset(f,0x3f,sizeof(f));
	f[0]=0,q.push({0,0});
	while(!q.empty())
	{
		int x=q.top().x;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			if(f[e[i].to]>f[x]+e[i].v)
			{
				f[e[i].to]=f[x]+e[i].v;
				q.push({e[i].to,f[e[i].to]});
			}
		}
	}
	ll ans=2147483647;
	for(int i=0;i<=m;i++)
		ans=min(ans,0ll+f[i]+abs(E[i].x-t.x)+abs(E[i].y-t.y));
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}