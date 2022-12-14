#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#define MN 100000
#define pa pair<double,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,K,Kind[MN+5],X[MN+5],Y[MN+5],Mx[MN+5],Mxfrom[MN+5],Ans[MN+5];
long long a[MN+5];
vector<int>add[MN+5],prd[MN+5];
bool cmp(int x,int y){return Y[x]<Y[y];}
bool cmpK(int x,int y){return Kind[x]<Kind[y];}
priority_queue<pa>q;
inline void TryInsertAdd(int x)
{
	if(!add[x].size()) return;
	q.push(make_pair((double)Y[add[x].back()]/a[x]+1,add[x].back()));	
}
inline void TryInsertPrd(int x)
{
	if(!prd[x].size()) return;
	q.push(make_pair((double)Y[prd[x].back()],prd[x].back()));
}
int main()
{
	n=read();m=read();K=read();int num=m;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i)
	{
		Kind[i]=read();X[i]=read();Y[i]=read();
		if(Kind[i]==1){if(Y[i]>Mx[X[i]])Mx[X[i]]=Y[i],Mxfrom[X[i]]=i;--num;} 
		if(Kind[i]==2)add[X[i]].push_back(i);
		if(Kind[i]==3)prd[X[i]].push_back(i);
	}
	for(int i=1;i<=n;++i) 
	{
		if(Mx[i]>a[i]) Y[Mxfrom[i]]=Mx[i]-a[i],add[i].push_back(Mxfrom[i]),++num;
		sort(add[i].begin(),add[i].end(),cmp);
		sort(prd[i].begin(),prd[i].end(),cmp);
		TryInsertAdd(i);TryInsertPrd(i); 
	}
	K=min(K,num);
	for(int i=1;i<=K;++i)
	{
		int x=q.top().second,y=X[x];q.pop();Ans[i]=x;
		if(Kind[x]<=2) a[y]+=Y[x],add[y].pop_back(),TryInsertAdd(y);
		else prd[y].pop_back(),TryInsertPrd(y);
	}
	sort(Ans+1,Ans+K+1,cmpK);printf("%d\n",K);
	for(int i=1;i<=K;++i) printf("%d ",Ans[i]);
	return 0;
}