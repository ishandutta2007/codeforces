#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 300001
#define MAXM 1000001
int N,M,mn[MAXM*4],tg[MAXM*4];pair<int,pair<int,int>>a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void pt(int k,int v){mn[k]+=v,tg[k]+=v;}void dwn(int k){if(tg[k])pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),mn[k]=min(mn[ls(k)],mn[rs(k)]):(pt(k,v),0):0;}
int main()
{
	N=get(),M=get();For(i,1,N)a[i].second.first=get(),a[i].second.second=get(),a[i].first=get();sort(a+1,a+N+1);
	int r=0,ans=1e9;For(i,1,N){while(r<N&&mn[1]!=1)r++,upd(1,1,M-1,a[r].second.first,a[r].second.second-1,1);if(mn[1]==1)ans=min(ans,a[r].first-a[i].first);else break;upd(1,1,M-1,a[i].second.first,a[i].second.second-1,-1);}
	cout<<ans<<endl;return 0;
}