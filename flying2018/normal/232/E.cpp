#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
#define N 600010
#define M 510
using namespace std;
bitset<M> f[M][M],g[M][M];
struct ques{
	int xl,yl,xr,yr,id;
}q[N];
vector<int>p;
int ans[N],n,m;
char mp[M][M];
void work(int l,int r,vector<int>& p)
{
	if(l>r || p.empty()) return;
	int mid=(l+r)>>1;
	for(int i=1;i<=m;i++) f[mid][i].reset(),g[mid][i].reset();
	for(int i=m;i>=1;i--)
		if(mp[mid][i]=='.') f[mid][i][i]=1,f[mid][i]|=f[mid][i+1];
	for(int i=1;i<=m;i++)
		if(mp[mid][i]=='.') g[mid][i][i]=1,g[mid][i]|=g[mid][i-1];
	for(int i=mid-1;i>=l;i--)
		for(int j=m;j>=1;j--)
		f[i][j]=(mp[i][j]=='.')?f[i+1][j]|f[i][j+1]:0;
	for(int i=mid+1;i<=r;i++)
		for(int j=1;j<=m;j++)
		g[i][j]=(mp[i][j]=='.')?g[i-1][j]|g[i][j-1]:0;
	vector<int>pl,pr;
	for(int i=0;i<p.size();i++)
	{
		if(q[p[i]].xr<mid){pl.push_back(p[i]);continue;}
		if(q[p[i]].xl>mid){pr.push_back(p[i]);continue;}
		ans[p[i]]=(f[q[p[i]].xl][q[p[i]].yl]&g[q[p[i]].xr][q[p[i]].yr]).any();
	}
	work(l,mid,pl);
	work(mid+1,r,pr);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	int qn;
	scanf("%d",&qn);
	for(int i=1;i<=qn;i++) scanf("%d%d%d%d",&q[i].xl,&q[i].yl,&q[i].xr,&q[i].yr);
	for(int i=1;i<=qn;i++) p.push_back(i);
	work(1,n,p);
	for(int i=1;i<=qn;i++) puts(ans[i]?"Yes":"No");
	return 0;
}