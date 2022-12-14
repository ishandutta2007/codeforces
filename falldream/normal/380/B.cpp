#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define MN 7000
#define MX 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,fa[MX+5],cnt=0;bool b[MN+5][MN+5];int Ans[MN+5];
struct ques{int k,t,l,r,x;}a[MN+5];
vector<pair<int,int> >v[MN+5]; 
map<int,int> mp;

int main()
{	
	n=read();m=read();
	for(int i=1,j=0,k=0;k<=MX;++i)
		if(i==(1<<j)) fa[++k]=i,fa[++k]=i,++j;
		else fa[++k]=i;
//	for(int i=1;i<=10;++i) cout<<"Fa["<<i<<"]="<<fa[i]<<endl;
	for(int i=1;i<=m;++i)
		if((a[i].k=read())==1)
		{
			a[i].t=read(),a[i].l=read(),a[i].r=read(),a[i].x=read();
			if(!mp[a[i].x]) mp[a[i].x]=++cnt;a[i].x=mp[a[i].x];	
		}
		else 
		{
			int t=read(),V=read();
			v[t].push_back(make_pair(V,i));
		}
	for(int i=1;i<=m;++i) if(a[i].k==1)
	{
		int l=a[i].l,r=a[i].r;
		for(int j=a[i].t;j;--j,l=fa[l],r=fa[r])
			for(int k=0;k<v[j].size();++k)
				if(v[j][k].first>=l&&v[j][k].first<=r&&i<=v[j][k].second)
					if(!b[v[j][k].second][a[i].x]) b[v[j][k].second][a[i].x]=1,++Ans[v[j][k].second]; 
	}
	else printf("%d\n",Ans[i]);
	return 0;
}