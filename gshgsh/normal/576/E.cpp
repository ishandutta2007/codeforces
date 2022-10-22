#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 500001
int N,M,K,Q,u[MAXN],v[MAXN],w[MAXN],f[51][MAXN*2],siz[51][MAXN*2],x[MAXN],c[MAXN],nxt[MAXN],top;pair<int,int>sta[MAXN*15];vector<pair<int,int>>id[MAXN*4],clr[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int c,int x){while(f[c][x]!=x)x=f[c][x];return x;}
void mrg(int c,int x,int y){x=getf(c,x),y=getf(c,y);if(x==y)return;if(siz[c][x]>siz[c][y])swap(x,y);f[c][x]=y;siz[c][y]+=siz[c][x];sta[++top]={c,x};}
void upd(int k,int l,int r,int x,int y,int c,int n){if(!c)return;if(l>=x&&r<=y)return id[k].push_back({n,c});x<=R&&(upd(ls(k),l,R,x,y,c,n),0),y>=L&&(upd(rs(k),L,r,x,y,c,n),0);}
void ask(int k,int l,int r)
{
	int lst=top;for(auto i:id[k])mrg(i.second,u[i.first],v[i.first]+N),mrg(i.second,u[i.first]+N,v[i.first]);
	if(l==r)if(getf(c[l],u[x[l]])!=getf(c[l],v[x[l]]))cout<<"YES\n",upd(1,1,Q,l+1,nxt[l],c[l],x[l]),w[x[l]]=c[l];else cout<<"NO\n",upd(1,1,Q,l+1,nxt[l],w[x[l]],x[l]);else ask(ls(k),l,R),ask(rs(k),L,r);
	while(top>lst){int c=sta[top].first,x=sta[top--].second;siz[c][f[c][x]]-=siz[c][x],f[c][x]=x;}
}
int main()
{
	N=get(),M=get(),K=get(),Q=get();For(i,1,N*2)For(j,0,K)f[j][i]=i,siz[j][i]=1;For(i,1,M)u[i]=get(),v[i]=get();
	For(i,1,Q)x[i]=get(),c[i]=get(),clr[x[i]].push_back({i,c[i]});For(i,1,M)clr[i].push_back({Q+1,0});
	For(i,1,Q)nxt[i]=lower_bound(clr[x[i]].begin(),clr[x[i]].end(),pair<int,int>(i+1,0))->first-1;ask(1,1,Q);return 0;
}