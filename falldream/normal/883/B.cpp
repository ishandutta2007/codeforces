#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define MN 200000
#define pa pair<int,int> 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,K,rk[MN+5],in[MN+5],q[MN+5],top,mx[MN+5],mn[MN+5],b[MN+5];
vector<int> v[MN+5],V[MN+5];
vector<pa >s[MN+5];
priority_queue<pa>Q;

int main()
{
	n=read();m=read();K=read();if(K>n) return 0*puts("-1");
	for(int i=1;i<=n;++i) b[rk[i]=read()]=1,mx[i]=rk[i]?rk[i]:K,mn[i]=rk[i]?rk[i]:1;
	for(int i=1,j,k;i<=m;++i) j=read(),k=read(),v[j].push_back(k),V[k].push_back(j),++in[k];
	for(int i=1;i<=n;++i) if(!in[i]) q[++top]=i;
	for(int i=1;i<=top;++i)
		for(int j=0;j<v[q[i]].size();++j)
			if(!--in[v[q[i]][j]]) q[++top]=v[q[i]][j];
	if(top!=n) return 0*puts("-1");
	for(int i=1;i<=n;++i)
		for(int j=0;j<v[q[i]].size();++j)
			mx[v[q[i]][j]]=min(mx[v[q[i]][j]],mx[q[i]]-1);
	for(int i=n;i;--i)
		for(int j=0;j<V[q[i]].size();++j)
			mn[V[q[i]][j]]=max(mn[V[q[i]][j]],mn[q[i]]+1);
	for(int i=1;i<=n;++i) if(mx[i]<mn[i]) return 0*puts("-1"); else s[mx[i]].push_back(make_pair(mn[i],i));
	for(int i=K;i;--i)
	{
		for(int j=0;j<s[i].size();++j) Q.push(s[i][j]);
		if(Q.empty()) return 0*puts("-1");
		int x=Q.top().second;Q.pop();rk[x]=i;
		while(!Q.empty()&&Q.top().first==i) rk[Q.top().second]=i,Q.pop();
	}
	for(int i=1;i<=n;++i) printf("%d ",rk[i]);
	return 0;
}