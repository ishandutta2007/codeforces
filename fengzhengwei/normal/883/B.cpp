#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int n,m,k,a[xx];
struct gragh
{
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
	int lim[xx],vis[xx];
	void tp(int op)
	{
		queue<int>q;
		for(int i=1;i<=n;i++)if(!rd[i])q.push(i);
		for(int i=1;i<=n;i++)lim[i]=op?k:1;
		while(!q.empty())
		{
			int x=q.front();
			vis[x]=1;
			q.pop();
			if(a[x])lim[x]=op?min(a[x],lim[x]):max(a[x],lim[x]);
			//op=1min 
			for(int i=h[x];i;i=e[i].next)
			{
				op?lim[e[i].to]=min(lim[e[i].to],lim[x]-1):lim[e[i].to]=max(lim[e[i].to],lim[x]+1);
				if(!(--rd[e[i].to]))q.push(e[i].to);
			}
		}
		for(int i=1;i<=n;i++)if(!vis[i])puts("-1"),exit(0);
	}
}L,R;
struct nod{int r,id;bool operator<(const nod&w)const{return r<w.r;};};
multiset<nod>s;
vector<nod>v[xx];
signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		R.add(a,b),L.add(b,a);
	}
	L.tp(0),R.tp(1);
	for(int i=1;i<=n;i++)if(L.lim[i]>R.lim[i])puts("-1"),exit(0);
//	for(int i=1;i<=n;i++)cout<<L.lim[i]<<" "<<R.lim[i]<<"\n";
	for(int i=1;i<=n;i++)v[L.lim[i]].push_back((nod){R.lim[i],i});
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<v[i].size();j++)s.insert(v[i][j]);
		if((s.begin()->r)<i)puts("-1"),exit(0);
		if((s.begin()->r)==i)
		{
			while((s.begin()->r)==i)
			{
				a[(s.begin()->id)]=i;
				s.erase(s.begin());
			}
		}
		else 
		{
			a[(s.begin()->id)]=i;
			s.erase(s.begin());
		}
	}
	for(int i=1;i<=n;i++)if(!a[i])puts("-1"),exit(0);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}