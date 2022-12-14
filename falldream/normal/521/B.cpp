#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#define MN 100000
#define mod 1000000009
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<pair<int,int>,int> mp;
set<int> s;set<int>::iterator it;
int n,b[MN+5],X[MN+5],Y[MN+5],c[MN+5][3],d[MN+5],del[MN+5],ans=0; 
void Update(int x)
{
	int can=1;
	for(int i=0;i<3;++i) if(!del[c[x][i]]&&d[c[x][i]]==1)can=0;
	if(can^b[x]) 
		if(b[x]=can) s.insert(x);
		else s.erase(s.find(x));	
}
void Update2(int x)
{
	for(int j=-1;j<=1;++j)
	{
		int y=mp[make_pair(X[x]+j,Y[x]-1)];
		if(!del[y]) Update(y);
	}
}
int main()
{
	n=read();del[0]=1;
	for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read(),mp[make_pair(X[i],Y[i])]=i;
	for(int i=1;i<=n;++i) for(int j=0;j<3;++j) ++d[c[i][j]=mp[make_pair(X[i]+j-1,Y[i]+1)]];
	for(int i=1;i<=n;++i) Update(i);
	for(int i=1;i<=n;++i)
	{	
		int x;
		if(~i&1) x=*s.begin(),s.erase(s.begin());
		else x=*(--(it=s.end())),s.erase(it);
		ans=(1LL*ans*n+x-1)%mod;del[x]=1;
		for(int j=0;j<3;++j) if(!del[c[x][j]]) --d[c[x][j]],Update2(c[x][j]);
		Update2(x);
	}
	printf("%d\n",ans);
	return 0;
}