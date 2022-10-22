#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN],b[MAXN],f[MAXN];set<int>val[MAXN];ll ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void mrg(int x,int y,int v)
{
	x=getf(x),y=getf(y);if(x==y)return;if(val[x].size()>val[y].size())swap(x,y);
	for(auto i:val[x])ans+=val[y].count(v-i);for(auto i:val[x])val[y].insert(i);f[x]=y;
}
int main()
{
	N=get();For(i,1,N)a[i]=get(),b[a[i]]=i,f[i]=i,val[i].insert(a[i]);
	For(i,1,N)b[i]>1&&i>a[b[i]-1]&&(mrg(b[i],b[i]-1,i),0),b[i]<N&&i>a[b[i]+1]&&(mrg(b[i],b[i]+1,i),0);
	cout<<ans<<'\n';return 0;
}