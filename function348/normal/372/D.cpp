#include<cstdio>
#include<iostream>
#include<set>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
typedef set<PII>::iterator SETI;
struct Edge {int y,ne;};
int n,k,num;
int g[N][20],dfn[N],de[N];
Edge e[N*2];int last[N];
set<PII> S;
int dis(int i,int j)
{
	int res=de[i]+de[j];
	if (de[i]<de[j]) swap(i,j);
	for (int p=18;p>=0;p--) if (de[i]-de[j]>=(1<<p)) i=g[i][p];
	for (int p=18;p>=0;p--) if (g[i][p]!=g[j][p]) i=g[i][p],j=g[j][p];
	if (i!=j) i=g[i][0];
	return res-2*de[i];
}
void dfs(int i,int fa)
{
	dfn[i]=++num;
	g[i][0]=fa;de[i]=de[fa]+1;
	for (int p=0;g[i][p];p++) g[i][p+1]=g[g[i][p]][p];
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa) dfs(e[j].y,i);
}
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
int check(int x)
{
//	printf("N:%d\n",x);
	S.clear();
	int k1,k2,now=0;
	for (int i=1;i<x;i++)
	{
		if (!S.empty())
		{
			SETI it=S.lower_bound(MP(dfn[i],i));
			if (it!=S.end()) k2=(*it).SC;else k2=(*S.begin()).SC;
			if (it==S.begin()) it=S.end();
			it--;
			k1=(*it).SC;
			now=now-dis(k1,k2)+dis(k1,i)+dis(k2,i);
		}
		S.insert(MP(dfn[i],i));
	}
	for (int i=x;i<=n;i++)
	{
		if (!S.empty())
		{
			SETI it=S.lower_bound(MP(dfn[i],i));
			if (it!=S.end()) k2=(*it).SC;else k2=(*S.begin()).SC;
			if (it==S.begin()) it=S.end();
			it--;
			k1=(*it).SC;
			now=now-dis(k1,k2)+dis(k1,i)+dis(k2,i);
		}

		S.insert(MP(dfn[i],i));
	//	printf("%d %d %d\n",i-x+1,i,now/2+1);
		if (now/2+1<=k) return 1;

		SETI it=S.find(MP(dfn[i-x+1],i-x+1));
		if (!S.empty())
		{
			SETI is=it;
			it++;
			if (it==S.end()) k2=(*S.begin()).SC;else k2=(*it).SC;
			it--;
			if (it==S.begin()) it=S.end();
			it--;
			k1=(*it).SC;
			now=now+dis(k1,k2)-dis(k1,i-x+1)-dis(k2,i-x+1);
			it=is;
		}
		S.erase(it);
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	num=0;
	dfs(1,0);
	int l=1,r=n;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (check(mid)) l=mid;else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}