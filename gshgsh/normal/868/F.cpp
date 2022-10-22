#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffffffffffff
#define MAXN 100001
int N,M,a[MAXN],cnt[MAXN];ll f[MAXN],g[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void solve(int l,int r,int x,int y,ll now)
{
	if(l>r)return;int mid=l+r>>1,mid2=0,r2=min(mid,y);
	For(i,l,mid)now+=cnt[a[i]]++;For(i,x,r2)now-=--cnt[a[i]],g[mid]>f[i]+now&&(g[mid]=f[i]+now,mid2=i);
	For(i,x,r2)now+=cnt[a[i]]++;For(i,l,mid)now-=--cnt[a[i]];solve(l,mid-1,x,mid2,now);
	For(i,l,mid)now+=cnt[a[i]]++;For(i,x,mid2-1)now-=--cnt[a[i]];solve(mid+1,r,mid2,y,now);
	For(i,x,mid2-1)cnt[a[i]]++;For(i,l,mid)cnt[a[i]]--;
}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=get();For(i,1,N)f[i]=f[i-1]+(cnt[a[i]]++);For(i,1,N)cnt[i]=0;
	For(i,2,M){For(i,1,N)g[i]=INF;solve(1,N,1,N,0);swap(f,g);}cout<<f[N]<<'\n';return 0;
}