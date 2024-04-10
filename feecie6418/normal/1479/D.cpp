#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
int rd(){
	int x;
	scanf("%d",&x);
	return x;
}
#else
int p1=5000000;
char buf[5000005];
int gc(){
	if(p1>=5000000)fread(buf,1,5000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
#endif
int n,Q,h[300005],s[300005],onp[300005],cnt,a[300005],bel[600005];
int sign,nowt,p[300005][20],d[300005],bel2[300005],cntb[3005],ccnt[300005];
int S[3005],E[3005],st[300005],blk,ans[300005],ed[300005],id[600005],lg2[300005]={-1};
struct Edge{
	int to,next;
}e[600005];
struct Query{
	int tp,l,r,x,y,id;
	int64_t h;
}q[300005];
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
inline bool operator <(Query a,Query b){
	//if(bel[a.x]!=bel[b.x])return bel[a.x]<bel[b.x];
	//return bel[a.x]&1?a.y<b.y:a.y>b.y;
	return a.h<b.h;
}
void Add_Edge(int x,int y){
	e[++cnt].to=y,e[cnt].next=h[x],h[x]=cnt;
}
void DFS(int now,int fa,int depth){
	p[now][0]=fa,d[now]=depth,st[now]=++sign,id[st[now]]=now;
	for(int i=1;i<=18;i++)p[now][i]=p[p[now][i-1]][i-1];
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		DFS(y,now,depth+1);
	}
	ed[now]=++sign,id[ed[now]]=now;
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=lg2[d[x]-d[y]];i>=0;i--)if(d[p[x][i]]>=d[y])x=p[x][i];
	if(x==y)return x;
	for(int i=lg2[d[x]];i>=0;i--)if(p[x][i]!=p[y][i])x=p[x][i],y=p[y][i];
	return p[x][0];
}
int Que(int l,int r){
	if(bel2[l]==bel2[r]){
		for(int j=l;j<=r;j++)if(ccnt[j]&1)return j;
		return -1;
	}
	for(int i=bel2[l]+1;i<bel2[r];i++){
		if(!cntb[i])continue;
		for(int j=S[i];j<=E[i];j++)if(ccnt[j]&1)return j;
	}
	for(int j=l;j<=E[bel2[l]];j++)if(ccnt[j]&1)return j;
	for(int j=S[bel2[r]];j<=r;j++)if(ccnt[j]&1)return j;
	return -1;
}
inline void Rev(int x){
	if(!onp[x])onp[x]=1,ccnt[a[x]]++;
	else onp[x]=0,ccnt[a[x]]--;
	if(ccnt[a[x]]&1)cntb[bel2[a[x]]]++;
	else cntb[bel2[a[x]]]--;
}
int main(){
	n=rd(),Q=rd(),blk=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=rd(),bel2[i]=i/blk+1,E[bel2[i]]=i,lg2[i]=lg2[i>>1]+1;
	for(int i=n;i;i--)S[bel2[i]]=i;
	for(int i=1,x,y;i<n;i++)x=rd(),y=rd(),Add_Edge(x,y),Add_Edge(y,x);
	DFS(1,0,1);
	for(int i=1;i<=sign;i++)bel[i]=i/blk+1;
	for(int i=1,x,y,l,r,t;i<=Q;i++){
		x=rd(),y=rd(),l=rd(),r=rd();
		if(st[x]>st[y])swap(x,y);
		if((t=LCA(x,y))==x)q[i]=(Query){0,l,r,st[x],st[y],i,0};
		else q[i]=(Query){t,l,r,ed[x],st[y],i,0};
		q[i].h=gilbertOrder(q[i].x,q[i].y,21,0);
	}
	sort(q+1,q+Q+1);
	for(int i=1,l=1,r=0;i<=Q;i++){
		while(l<q[i].x)Rev(id[l++]);
		while(l>q[i].x)Rev(id[--l]);
		while(r<q[i].y)Rev(id[++r]);
		while(r>q[i].y)Rev(id[r--]);
		if(q[i].tp)Rev(q[i].tp);
		ans[q[i].id]=Que(q[i].l,q[i].r);
		if(q[i].tp)Rev(q[i].tp);
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}