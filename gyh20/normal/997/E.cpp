#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=200000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int mn[480002],a[240002],stk1[240002],m,tp1,stk2[240002],tp2,tg[480002],n,tim,stk[240002],tp,st1[22][240002],st2[22][240002],lg[240002],dfn[240002],pl[240002],typ[240002],head[240002],cnt,tot,M[240002],L[240002],R[240002],fa[240002],dep[240002],siz[240002],top[240002],son[240002];
long long ans[240002],sum[240002];
vector<int>ss[240002];
struct node{int x,y,z;};
vector<node>v[240002];
struct BIT{
	long long c[120002];
	inline void add(re int x,re int y){for(;x<=n;x+=x&(-x))c[x]+=y;}
	inline long long ask(re int x){re long long s=0;for(;x;x^=x&(-x))s+=c[x];return s;}
}C1,C2;
struct edge{int to,next;}e[240002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt,ss[x].push_back(y);}
inline void add(re int x,re int y){
	mn[x]+=y,tg[x]+=y;
}
inline void pd(re int p){
	if(tg[p])add(p<<1,tg[p]),add(p<<1|1,tg[p]),tg[p]=0;
}
inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y)return add(p,z);
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,z);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
inline int ask(re int p,re int l,re int r){
	if(l==r)return l;
	pd(p);
	re int mid=l+r>>1;
	if(mn[p<<1])return ask(p<<1|1,mid+1,r);
	return ask(p<<1,l,mid);
}
inline int askmn(re int l,re int r){
	re int tmp=lg[r-l+1];
	return min(st1[tmp][l],st1[tmp][r-(1<<tmp)+1]);
}
inline int askmx(re int l,re int r){
	re int tmp=lg[r-l+1];
	return max(st2[tmp][l],st2[tmp][r-(1<<tmp)+1]);
}
inline bool ck(re int l,re int r){
	return askmx(l,r)-askmn(l,r)==r-l;
}
inline void dfs1(re int x,re int y){
	dep[x]=dep[y]+1,siz[x]=1,fa[x]=y;
	for(re int i=head[x];i;i=e[i].next){
		dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
	}
}
inline void dfs2(re int x,re int y){
	top[x]=y,dfn[x]=++tim,pl[tim]=x;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^son[x])dfs2(e[i].to,e[i].to);
}
inline int lca(re int x,re int y){
	while(top[x]^top[y])
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
inline int nxt(re int x,re int y){
	while(top[x]^top[y]){
		if(fa[top[x]]==y)return top[x];
		x=fa[top[x]];
	}
	return pl[dfn[y]+1];
}
inline void solve(re int x){
	re int num=0;
	for(re int i=0;i<ss[x].size();++i)son[ss[x][i]]=num++,solve(ss[x][i]),sum[x]+=sum[ss[x][i]];
	if(typ[x]){
		for(re int i=1;i<ss[x].size();++i)C2.add(R[ss[x][i]],i),sum[x]+=i;
		for(re int i=ss[x].size()-2;~i;--i)C1.add(L[ss[x][i]],ss[x].size()-i-1);
		for(re int i=0;i<v[x].size();++i){
			re int l=nxt(v[x][i].x,x),r=nxt(v[x][i].y,x);
			ans[v[x][i].z]=sum[x]-C1.ask(v[x][i].x-1)+C1.ask(L[x]-1)-C2.ask(R[x])+C2.ask(v[x][i].y)+(son[l]+1ll-(v[x][i].x==L[l]))*(ss[x].size()-son[r]-(v[x][i].y==R[r]));
		}
	}
	else{
		C1.add(L[x],1),C2.add(R[x],1),++sum[x];
		for(re int i=0;i<v[x].size();++i)ans[v[x][i].z]=sum[x]-C1.ask(v[x][i].x-1)+C1.ask(L[x]-1)-C2.ask(R[x])+C2.ask(v[x][i].y)+(v[x][i].x!=L[x]&&v[x][i].y!=R[x]);
	}
}
int main(){
	tot=n=read(),lg[0]=-1;
	for(re int i=1;i<=n;++i)a[i]=read(),lg[i]=lg[i>>1]+1,st1[0][i]=st2[0][i]=a[i];
	for(re int i=1;i<=lg[n];++i)for(re int j=1;j+(1<<i)-1<=n;++j)st1[i][j]=min(st1[i-1][j],st1[i-1][j+(1<<i-1)]),st2[i][j]=max(st2[i-1][j],st2[i-1][j+(1<<i-1)]);
	for(re int i=1;i<=n;++i){
		while(tp1&&a[i]>a[stk1[tp1]])add(1,1,n,stk1[tp1-1]+1,stk1[tp1],-a[stk1[tp1]]),--tp1;
		while(tp2&&a[i]<a[stk2[tp2]])add(1,1,n,stk2[tp2-1]+1,stk2[tp2],a[stk2[tp2]]),--tp2;
		add(1,1,n,stk1[tp1]+1,i,a[i]),add(1,1,n,stk2[tp2]+1,i,-a[i]),L[i]=R[i]=i;
		re int pos=ask(1,1,n),now=i;
		while(tp&&L[stk[tp]]>=pos){
			if(typ[stk[tp]]&&ck(M[stk[tp]],i))R[stk[tp]]=i,addd(stk[tp],now),now=stk[tp--];
			else if(ck(L[stk[tp]],i))++tot,typ[tot]=1,addd(tot,stk[tp]),addd(tot,now),L[tot]=L[stk[tp]],R[tot]=i,M[tot]=L[now],now=tot,--tp;
			else{
				++tot,addd(tot,now);
				do{addd(tot,stk[tp--]);}while(tp&&!ck(L[stk[tp]],i));
				L[tot]=L[stk[tp]],R[tot]=i,addd(tot,stk[tp--]),now=tot;
			}
		}
		stk[++tp]=now,stk1[++tp1]=i,stk2[++tp2]=i,add(1,1,n,1,i,-1);
	}
	dfs1(stk[1],stk[1]),dfs2(stk[1],stk[1]);
	m=read();
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),v[lca(x,y)].push_back((node){x,y,i});
	solve(stk[1]);
	for(re int i=1;i<=m;++i)printf("%lld\n",ans[i]);
}