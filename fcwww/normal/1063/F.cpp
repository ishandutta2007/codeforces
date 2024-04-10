#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 1000050
#define db(x) cerr<<#x<<" = "<<x<<endl
#define ls p<<1
#define rs p<<1|1
char w[N];
int ch[N][26],fa[N],len[N],lst=1,cnt=1,pos[N];
int head[N],to[N],nxt[N],tot;
int f[22][N],Lg[N],dp[N],ans,dfn[N],enp[N];
int mx[N<<2],n;
inline void add(int u,int v) {
	to[++tot]=v; nxt[tot]=head[u]; head[u]=tot;
}
void update(int l,int r,int x,int v,int p) {
	mx[p]=max(mx[p],v);if(l==r) return ;
	int mid=(l+r)>>1; if(x<=mid) update(l,mid,x,v,ls); else update(mid+1,r,x,v,rs);
}
int query(int l,int r,int x,int y,int p) {
	if(x<=l&&y>=r) return mx[p];
	int mid=(l+r)>>1,re=0;
	if(x<=mid) re=max(re,query(l,mid,x,y,ls));
	if(y>mid) re=max(re,query(mid+1,r,x,y,rs));
	return re;
}
void insert(int x,int id) {
	int p=lst,np=++cnt,q,nq;
	lst=np; len[np]=len[p]+1;
	for(;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if(!p) fa[np]=1;
	else {
		q=ch[p][x];
		if(len[q]==len[p]+1) fa[np]=q;
		else {
			nq=++cnt; fa[nq]=fa[q]; memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[q]=fa[np]=nq; len[nq]=len[p]+1;
			for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}
	pos[id]=lst;
}
void dfs(int x) {
	int i; dfn[x]=++dfn[0];
	f[0][x]=fa[x];
	for(i=1;(1<<i)<=cnt;i++) f[i][x]=f[i-1][f[i-1][x]];
	for(i=head[x];i;i=nxt[i]) {
		dfs(to[i]);
	}enp[x]=dfn[0];
}
int LEN;
int getp(int x,int d) {
	x=pos[x];
	int i;
	for(i=20;i>=0;i--) {
		if(f[i][x]&&len[f[i][x]]>=d) x=f[i][x];
	}return x;
}
bool check(int x,int d) {
	if(d==1) return 1;
	if(x-d+1<1) return 0;
	int p=getp(x,d-1);
	if(query(1,cnt,dfn[p],enp[p],1)>=d-1) return 1;
	p=getp(x-1,d-1);
	if(query(1,cnt,dfn[p],enp[p],1)>=d-1) return 1;
	return 0;
}
int main() {
	scanf("%d%s",&n,w+1);
	reverse(w+1,w+n+1);
	int i,j=n;
	for(i=1;i<=n;i++) insert(w[i]-'a',i);
	for(i=2;i<=cnt;i++) add(fa[i],i);
	dfs(1);
	LEN=0; while((1<<LEN)<=cnt)LEN++;
	for(i=1,j=0;i<=n;i++) {
		dp[i]=dp[i-1]+1;
		while(!check(i,dp[i])) {
			dp[i]--;
			j++;
			update(1,cnt,dfn[getp(j,dp[j])],dp[j],1);
		}
		ans=max(ans,dp[i]);
	}
	// for(i=n;i;i--) db(dp[i]);
	printf("%d\n",ans);

	return 0;
}