#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio> 
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
#define ll long long 
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
using namespace std;
inline ll read()
{
    ll t=0,f=1;char tmp=getchar();
    while(tmp<'0'||tmp>'9')   {if(tmp=='-')	f=-1;tmp=getchar();}
    while(tmp>='0'&&tmp<='9') t=t*10+tmp-48,tmp=getchar();
    return t*f;
}
set<int> cun[200001];
bool vis[200001];
int n,m,c[200001],cnt,poi[300001],nxt[300001],head[300001];
bool hav[200001];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
int x,y,ans,ans1;
int main()
{
	n=read();m=read();
	For(i,1,n)	c[i]=read(),hav[c[i]]=1;
	For(i,1,m)	x=read(),y=read(),add(x,y),add(y,x);
	For(i,1,n)
		for(int j=head[i];j;j=nxt[j])
			if(c[i]!=c[poi[j]])cun[c[i]].insert(c[poi[j]]);
	ans=-1;
	For(i,1,100000)
	{
		if(hav[i])
		if((int)cun[i].size()>ans)	ans=cun[i].size(),ans1=i;
	}
	cout<<ans1<<endl;
}