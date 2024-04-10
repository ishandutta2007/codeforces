#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,M,a[MAXN],b[MAXN],ans[MAXN],f[MAXN],siz[MAXN];ll v[MAXN];
struct cmp{bool operator()(const int&x,const int&y)const{return v[x]*siz[y]!=v[y]*siz[x]?v[x]*siz[y]>v[y]*siz[x]:x<y;}};
set<int,cmp>s;multiset<int,greater<int>>s2;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	N=get(),M=get();For(i,1,N)v[i]=a[i]=get();For(i,1,M)b[i]=get();
	For(i,1,N)f[i]=i,siz[i]=1,s.insert(i),s2.insert(1);f[N+1]=N+1;
	FOR(i,M,1)
	{
		while(!s.empty())
		{
			int x=*s.begin();if(1ll*siz[x]*b[i]>=v[x])break;s.erase(x);s2.erase(s2.find(siz[x]));
			int p=getf(x+1);if(p<=N)s.erase(p),s2.erase(s2.find(siz[p])),siz[p]+=siz[x],v[p]+=v[x],s.insert(p),s2.insert(siz[p]);else siz[N+1]+=siz[x];f[x]=p;
		}
		ans[i]=max(siz[N+1],*s2.begin())-1;
	}
	For(i,1,M)cout<<ans[i]<<" \n"[i==M];
}