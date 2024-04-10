#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int N,M,a[MAXN],p[MAXN][20],pos[MAXN][20];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void insert(int id,int v)
{
	int x=id;For(i,0,19)p[x][i]=p[x-1][i],pos[x][i]=pos[x-1][i];
	FOR(i,19,0)if((v>>i)&1){if(!p[x][i]){p[x][i]=v,pos[x][i]=id;return;}if(pos[x][i]<id)swap(pos[x][i],id),swap(p[x][i],v);v^=p[x][i];}
}
int main()
{
	N=get();For(i,1,N)a[i]=get(),insert(i,a[i]);
	M=get();For(i,1,M){int l=get(),r=get();int ans=0;FOR(i,19,0)if(p[r][i]&&pos[r][i]>=l)ans=max(ans,ans^p[r][i]);cout<<ans<<'\n';}return 0;
}