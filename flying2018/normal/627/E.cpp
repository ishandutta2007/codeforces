#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long
#define N 3010
using namespace std;
int x[N],y[N];
vector<int>py[N];
int L[N],R[N],q,k;
void nxt(int &u,int k=1){while(k --> 0) u=R[u];}
void pre(int &u,int k=1){while(k --> 0) u=L[u];}
ll res=0;
struct node{
	int x,y;
	bool operator <(const node a)const{return x<a.x;}
}p[N];
int n,m;
void solve()
{
	res=0;
	int l=0,r=0;
	nxt(r,k);
	if(r==q+1) return;
	for(;r!=q+1;nxt(r))
	{
		nxt(l);
		res+=1ll*p[l].x*(p[R[r]].x-p[r].x);
	}
}
void del(int u){R[L[u]]=R[u],L[R[u]]=L[u];}
void erase(int u)
{
	int l=u;pre(l,k+1);int l0=l;
	int r=l;nxt(r,k);
	for(;l<u && r<q+1;nxt(r))
	{
		nxt(l);
		res-=1ll*p[l].x*(p[R[r]].x-p[r].x);
	}
	del(u);
	l=r=l0;nxt(r,k);
	for(;R[l]<u && r<q+1;nxt(r))
	{
		nxt(l);
		res+=1ll*p[l].x*(p[R[r]].x-p[r].x);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&q,&k);
	for(int i=1;i<=q;i++) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+q+1);
	p[q+1]=(node){n+1,m+1};
	for(int i=1;i<=q;i++) py[p[i].y].push_back(i);
	ll ans=0;
	R[q+1]=q+1;
	for(int y0=1;y0<=m;y0++)
	{
		int pr=0;
		for(int i=1;i<=q;i++) if(p[i].y<=y0) L[i]=pr,pr=i;else L[i]=0;
		L[q+1]=pr;
		pr=q+1;
		for(int i=q;i>=1;i--) if(p[i].y<=y0) R[i]=pr,pr=i;else R[i]=0;
		R[0]=pr;
		solve();
		ans+=res;
		for(int y=1;y<=y0;y++)
		{
			for(int u:py[y]) erase(u);
			ans+=res;
		}
	}
	printf("%lld\n",ans);
	return 0;
}