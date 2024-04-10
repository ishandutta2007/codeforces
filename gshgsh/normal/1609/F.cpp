#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define getchar() In[pos++]
#define R (l+r>>1)
#define L (l+r>>1)+1
#define ls(x) x<<1
#define rs(x) x<<1|1
#define MAXN 1000001
#define siz 21000000
int N,top,sta[MAXN],l1[MAXN],r1[MAXN],l2[MAXN],r2[MAXN],mx[MAXN*4],cnt[MAXN*4],tg[MAXN*4];ll a[MAXN],ans;vector<pair<pair<int,int>,pair<int,int>>>opt[60];char In[siz+100];int pos;
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void pt(int k,int v){mx[k]+=v,tg[k]+=v;}void dwn(int k){pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void build(int k,int l,int r){if(l!=r)build(ls(k),l,R),build(rs(k),L,r),cnt[k]=cnt[ls(k)]+cnt[rs(k)];else cnt[k]=1;}
void pushup(int k){mx[k]=max(mx[ls(k)],mx[rs(k)]);cnt[k]=0;mx[ls(k)]==mx[k]&&(cnt[k]+=cnt[ls(k)]),mx[rs(k)]==mx[k]&&(cnt[k]+=cnt[rs(k)]);}
void upd(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return pt(k,v);dwn(k);if(x<=R)upd(ls(k),l,R,x,y,v);if(y>=L)upd(rs(k),L,r,x,y,v);pushup(k);}
int main()
{
	fread(In,siz,1,stdin);N=get();For(i,1,N)a[i]=get();build(1,1,N);
	sta[top=0]=0;For(i,1,N){while(top&&a[i]>a[sta[top]])top--;l1[i]=sta[top]+1;sta[++top]=i;}
	sta[top=0]=N+1;FOR(i,N,1){while(top&&a[i]>=a[sta[top]])top--;r1[i]=sta[top]-1;sta[++top]=i;}
	sta[top=0]=0;For(i,1,N){while(top&&a[i]<a[sta[top]])top--;l2[i]=sta[top]+1;sta[++top]=i;}
	sta[top=0]=N+1;FOR(i,N,1){while(top&&a[i]<=a[sta[top]])top--;r2[i]=sta[top]-1;sta[++top]=i;}
	For(i,1,N){int v=__builtin_popcountll(a[i]);opt[v].push_back({{l1[i],1},{i,r1[i]}});opt[v].push_back({{i+1,-1},{i,r1[i]}});opt[v].push_back({{l2[i],1},{i,r2[i]}});opt[v].push_back({{i+1,-1},{i,r2[i]}});}
	For(i,0,59)if(!opt[i].empty())
	{
		sort(opt[i].begin(),opt[i].end());int M=opt[i].size();
		upd(1,1,N,opt[i][0].second.first,opt[i][0].second.second,opt[i][0].first.second);
		For(j,1,M-1)ans+=(mx[1]==2?cnt[1]:0)*(opt[i][j].first.first-opt[i][j-1].first.first),upd(1,1,N,opt[i][j].second.first,opt[i][j].second.second,opt[i][j].first.second);
		ans+=(mx[1]==2?cnt[1]:0)*(N+1-opt[i][M-1].first.first);
	}
	cout<<ans<<'\n';return 0;
}