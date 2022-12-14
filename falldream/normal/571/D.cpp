#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#define MN 500000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5],V[MN+5];
vector<pair<int,long long> >t[MN+5];
int n,m,last[MN+5],s[MN+5],S[MN+5],T[MN+5],U[MN+5],M[MN+5];long long val[MN+5];
inline int getfa(int*fa,int x){return fa[x]?fa[x]=getfa(fa,fa[x]):x;}
char op[10];

void AddTag(int i,int x)
{
	int V=v[x].size();
	long long pre=t[x].size()?t[x][t[x].size()-1].second:0;	
	t[x].push_back(make_pair(i,pre+V));
}
void AddZeroTag(int i,int x){T[x]=max(T[x],i);}
void Merge_U(int tm,int x,int y)
{
	x=getfa(s,x);y=getfa(s,y);
	if(v[x].size()<v[y].size()) swap(x,y);	
	long long tot=t[y].size()?t[y][t[y].size()-1].second:0;
	for(int j=0;j<v[y].size();++j)
	{
		int p=v[y][j];
		if(T[M[p]]>last[p]) last[p]=T[M[p]],val[p]=0;
		int pos=lower_bound(t[y].begin(),t[y].end(),make_pair(last[p],0LL))-t[y].begin();
		if(pos<t[y].size()) val[p]+=tot-(pos==0?0:t[y][pos-1].second);
		last[p]=tm;U[p]=x;v[x].push_back(p);
	}
	s[y]=x;
}

void Merge_M(int tm,int x,int y)
{
	x=getfa(S,x);y=getfa(S,y);
	if(V[x].size()<V[y].size()) swap(x,y);
	for(int j=0;j<V[y].size();++j)
	{
		int p=V[y][j];
		if(T[y]>last[p]) last[p]=T[y],val[p]=0;
		long long tot=t[U[p]].size()?t[U[p]][t[U[p]].size()-1].second:0;
		int pos=lower_bound(t[U[p]].begin(),t[U[p]].end(),make_pair(last[p],0LL))-t[U[p]].begin();
		if(pos<t[U[p]].size()) val[p]+=tot-(pos==0?0:t[U[p]][pos-1].second);
		last[p]=tm;M[p]=x;V[x].push_back(p);	
	}
	S[y]=x;
}

long long Query(int tm,int x)
{
	if(T[M[x]]>last[x]) last[x]=T[M[x]],val[x]=0;
	long long tot=t[U[x]].size()?t[U[x]][t[U[x]].size()-1].second:0;
	int pos=lower_bound(t[U[x]].begin(),t[U[x]].end(),make_pair(last[x],0LL))-t[U[x]].begin();
	if(pos<t[U[x]].size()) val[x]+=tot-(pos==0?0:t[U[x]][pos-1].second);
	last[x]=tm;return val[x];
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) v[i].push_back(i),V[i].push_back(i),U[i]=i,M[i]=i;
	for(int i=1,j;i<=m;++i)
	{
		scanf("%s",op+1);
		if(op[1]=='U') Merge_U(i,read(),read());
		if(op[1]=='M') Merge_M(i,read(),read());
		if(op[1]=='A') j=read(),AddTag(i,getfa(s,j));
		if(op[1]=='Z') AddZeroTag(i,getfa(S,read()));
		if(op[1]=='Q') printf("%lld\n",Query(i,read()));
	}
	return 0;
}