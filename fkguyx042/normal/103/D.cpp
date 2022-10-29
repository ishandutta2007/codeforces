#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 300001
#define K 500
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,w[N],x,y;
vector<pair<int,int> >v[K+5];
long long f[N],ans[N];
void baoli(int id)
{
	  long long i;
	  for (i=x;i<=n;i+=y) ans[id]+=w[i];
}
void work(int x)
{
	  int i;
	  for (i=n;i;--i)
	  {
	  	 f[i]=w[i];
	  	 if (i+x<=n) f[i]+=f[i+x];
	  }
	  for (i=0;i<(int)v[x].size();++i) 
	   ans[v[x][i].fi]=f[v[x][i].se];
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&w[i]);
	 scanf("%d",&m);
	 for (i=1;i<=m;++i)
	 {
	 	  scanf("%d%d",&x,&y);
	 	  if (y>K) baoli(i); else v[y].push_back(mk(i,x));
	 }
	 for (i=1;i<=K;++i) work(i);
	 for (i=1;i<=m;++i) printf("%I64d\n",ans[i]);
}