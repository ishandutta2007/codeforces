#include<bits/stdc++.h>
#define ll long long
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
int T,n,m;
const int xx=2e5+5;
struct node{int next,to;}e[xx];
int cnt,h[xx],rd[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	rd[y]++;
}
int uu[xx],vv[xx],id[xx],ss[xx];

signed main(){
	T=read();
	while(T--)
	{
		n=read(),m=read();
		memset(e,0,sizeof(e[0])*(cnt+1));
		cnt=0;
		memset(h,0,sizeof(h[0])*(n+1));
		memset(rd,0,sizeof(rd[0])*(n+1));
		memset(ss,0,sizeof(ss[0])*(n+1));
		for(int i=1;i<=m;i++)
		{
			id[i]=read(),uu[i]=read(),vv[i]=read();
			if(id[i])add(uu[i],vv[i]);
		}
		queue<int>q;
		for(int i=1;i<=n;i++)if(!rd[i])q.push(i);
		int cst=0;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			ss[x]=++cst;
			for(int i=h[x];i;i=e[i].next)
			{
				rd[e[i].to]--;
				if(!rd[e[i].to])q.push(e[i].to);
			}
		}
		int vis=0;
		for(int i=1;i<=n;i++)if(!ss[i]){puts("NO"),vis=1;break;}
		if(vis)continue;
		puts("YES");
		for(int i=1;i<=m;i++)
		{
			if(id[i]||ss[uu[i]]<ss[vv[i]])cout<<uu[i]<<" "<<vv[i]<<'\n';
			else cout<<vv[i]<<" "<<uu[i]<<'\n';
		}
	}
	return 0;
}