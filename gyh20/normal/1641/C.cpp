#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,sz[800002],num[800002],pos[800002],c[800002],cc[800002],fa[200002],vv[800002],tot,len[800002],L[800002],R[800002],U[800002];
set<int>S[200002];
vector<int>V[1200002];
queue<int>Q;
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void pu(re int p){
	num[p]=num[p<<1]+num[p<<1|1];
	if(num[p<<1]!=len[p<<1])pos[p]=pos[p<<1];
	else pos[p]=pos[p<<1|1];
}
inline void Add(re int x){
	for(;x<=n;x+=x&(-x))++c[x];
}
inline int ask(re int x,re int s=0){
	for(;x;x^=x&(-x))s+=c[x];
	return s;
}
inline void Clr(re int l,re int r){
	for(re int i=root(l);i<=r;i=root(i+1))Q.push(i),fa[i]=i+1;
}
inline void Clr(re int p,re int l,re int r,re int x){
	for(re int i=0;i<V[p].size();++i)cc[V[p][i]]=1;
	V[p].clear();vv[p]=1;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)Clr(p<<1,l,mid,x);
	else Clr(p<<1|1,mid+1,r,x);
}
inline void Sick(re int x){
	if(U[x])return;
	U[x]=1;
	Add(x),fa[x]=x+1;
	Clr(1,1,n,x);
}
inline void chk(re int x){
	if(cc[x])return;
	if(sz[x]==R[x]-L[x])Sick(pos[*S[x].begin()]);
}
inline void ck(re int p){
	if(len[p]==num[p]){
		for(re int i=0;i<V[p].size();++i)S[V[p][i]].erase(p),++sz[V[p][i]],chk(V[p][i]);
	}
	else{
		for(re int i=0;i<V[p].size();++i)sz[V[p][i]]+=num[p],chk(V[p][i]);
	}
} 
inline void add(re int p,re int l,re int r,re int x){
	if(l==r){
		++num[p];
		ck(p);
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x);
	else add(p<<1|1,mid+1,r,x);
	pu(p);
	if(num[p]==len[p]||num[p]==len[p]-1)ck(p);
}
inline void build(re int p,re int l,re int r){
	len[p]=r-l+1;
	if(l==r){
		pos[p]=l;
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	pu(p);
}
inline void ins(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y){
		if(vv[p]){
			cc[z]=1;
			return;
		}
		S[z].insert(p);
		if(len[p]-1<=num[p])sz[z]+=num[p];
		if(len[p]==num[p])S[z].erase(p);
		V[p].push_back(z);
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)ins(p<<1,l,mid,x,y,z);
	if(y>mid)ins(p<<1|1,mid+1,r,x,y,z);
}
int main(){
	n=read(),m=read();build(1,1,n);srand(114514);
	for(re int i=1;i<=n;++i)fa[i]=i;fa[n+1]=n+1;
	while(m--){
		re int o=read(),l,r,x;
		if(o==0){
			re int l=read(),r=read(),x=read();
			if(l>r)swap(l,r);
			++tot,L[tot]=l,R[tot]=r;
			if(x==0)Clr(l,r);
			else {
				ins(1,1,n,l,r,tot);
				chk(tot);
			}
			while(!Q.empty()){
				re int x=Q.front();
				add(1,1,n,x);
				Q.pop();
			}
		}
		else{
			x=read();
			if(fa[x]==x)puts("N/A");
			else if(ask(x)!=ask(x-1))puts("YES");
			else puts("NO");
		}
	}
}