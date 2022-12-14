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
vector<pair<int,pair<int,int> > > v[MN*4+5];
vector<pair<int*,int> >tag[52];
int n,m,K,q,X[MN+5],Y[MN+5],E[MN+5],C[MN+5],col[MN+5],Sz[50][52],la[MN+5],ne[MN+5];
int s[52][MN+5],val[52][MN+5],size[52][MN+5];
inline int getfa(int c,int x){return s[c][x]?getfa(c,s[c][x]):x;}
inline int getval(int c,int x){return s[c][x]?val[c][x]^getval(c,s[c][x]):0;}
void Save(int x){for(int i=1;i<=K;++i)Sz[x][i]=tag[i].size();}
void Back(int x)
{
	for(int i=1;i<=K;++i)
		while(tag[i].size()>Sz[x][i]) 
		{
			(*tag[i][tag[i].size()-1].first)=tag[i][tag[i].size()-1].second;
			tag[i].pop_back();
		}
}
void R(int c,int&x,int y){tag[c].push_back(make_pair(&x,x));x=y;}
void Merge(int c,int x,int y)
{
	int f1=getfa(c,x),f2=getfa(c,y);
	if(f1==f2) return;if(size[f1]<size[f2]) swap(f1,f2),swap(x,y);
	R(c,val[c][f2],1^getval(c,y)^getval(c,x));R(c,s[c][f2],f1);R(c,size[c][f1],size[c][f1]+size[c][f2]);
}
void Modify(int x,int l,int r,int L,int R,pair<int,pair<int,int> >k)
{
	if(l==L&&r==R){v[x].push_back(k);return;}
	int mid=L+R>>1;
	if(r<=mid) Modify(x<<1,l,r,L,mid,k);
	else if(l>mid) Modify(x<<1|1,l,r,mid+1,R,k);
	else Modify(x<<1,l,mid,L,mid,k),Modify(x<<1|1,mid+1,r,mid+1,R,k); 
}
void Solve(int dep,int x,int l,int r)
{
	Save(dep);
	for(int i=0;i<v[x].size();++i)
		Merge(v[x][i].first,v[x][i].second.first,v[x][i].second.second);
	if(l==r)
	{
		int rescol;
		if(getfa(C[l],X[E[l]])==getfa(C[l],Y[E[l]])&&getval(C[l],X[E[l]])==getval(C[l],Y[E[l]]))
			 puts("NO"),rescol=col[E[l]];
		else puts("YES"),rescol=col[E[l]]=C[l];
		int nxt=ne[l]?ne[l]:q+1;
		if(l<nxt-1&&rescol) Modify(1,l+1,nxt-1,1,q,make_pair(rescol,make_pair(X[E[l]],Y[E[l]])));
	}
	else Solve(dep+1,x<<1,l,l+r>>1),Solve(dep+1,x<<1|1,(l+r)/2+1,r);
	Back(dep);
}

int main()
{
	n=read();m=read();K=read();q=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=K;++j)size[j][i]=1;
	for(int i=1;i<=m;++i) X[i]=read(),Y[i]=read();
	for(int i=1;i<=q;++i)
	{
		E[i]=read();C[i]=read();
		if(la[E[i]]) ne[la[E[i]]]=i;
		la[E[i]]=i;
	}
	Solve(1,1,1,q);
	return 0;
}