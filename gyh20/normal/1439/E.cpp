#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,A[100002],B[100002],C[100002],D[100002],inf=1<<30,tot,rt,fa[500002],w[500002],O,tg[500002];
vector<int>G[500002]; 
struct node{
	int x,y,id;
	bool operator <(const node A)const{return x==A.x?y<A.y:x<A.x;}
	bool operator ==(const node A)const{return x==A.x&&y==A.y;}
}p[500002];
map<node,int>P;map<int,int>ans;
inline int solve(re int l1,re int r1,re int l2,re int r2,vector<node>&tt){
	for(auto z:tt)assert(z.x>=l1&&z.x<=r1&&z.y>=l2&&z.y<=r2); 
	if(!tt.size())return 0;
	if(tt.size()==1)return tt[0].id;
	re int m1=l1+r1>>1,m2=l2+r2>>1;
	vector<node>V1,V2,V3;
	for(auto z:tt)
		if(z.x<=m1&&z.y<=m2)V1.push_back(z);
		else if(z.x<=m1)V2.push_back(z);
		else V3.push_back(z);
	int R1=solve(l1,m1,m2+1,r2,V2),R2=solve(m1+1,r1,l2,m2,V3);
	node tmp=(node){l1,m2};
	if(r1==l1+1&&R1&&R2&&!P.count((node){l1,l2})){
		tmp=(node){l1,l2};
		P[tmp]=++tot,tmp.id=tot,p[tot]=tmp,V1.push_back(tmp);
	}tmp=(node){l1,m2};
	if(R1){
		if(!P.count(tmp))tmp.id=R1,V1.push_back(tmp);
		else fa[R1]=P[tmp];
	}
	if(R2){
		tmp=(node){m1,l2};
		if(!P.count(tmp))tmp.id=R2,V1.push_back(tmp);
		else fa[R2]=P[tmp];
	}
	return solve(l1,m1,l2,m2,V1);
}
inline int dep(re int x){return p[x].x+p[x].y;}
inline int lca(re int l1,re int r1,re int l2,re int r2,re node x,re node y){
	if(l1==r1)return P[(node){l1,l2}];
	re int m1=l1+r1>>1,m2=l2+r2>>1;
	re int t1=(x.x>m1)*2+(x.y>m2),t2=(y.x>m1)*2+(y.y>m2);
	if(t1==t2){
		if(t1==0)return lca(l1,m1,l2,m2,x,y);
		else if(t1==2)return lca(m1+1,r1,l2,m2,x,y);
		return lca(l1,m1,m2+1,r2,x,y);
	}
	if(t1+t2==3)return P[(node){l1,l2}];
	if(t1>t2)swap(x,y),swap(t1,t2);
	if(t2==1){
		y.x=l1,y.y=m2;
		return lca(l1,m1,l2,m2,x,y);
	}
	else{
		y.x=m1,y.y=l2;
		return lca(l1,m1,l2,m2,x,y);
	}
}
vector<node>V;
inline void dfs(re int x){
	for(auto z:G[x])dfs(z),w[x]+=w[z];
	if(w[x])ans[dep(x)+1]^=1,ans[dep(fa[x])+1]^=1;
	else if(tg[x])ans[dep(x)]^=1,ans[dep(x)+1]^=1;
}
int main(){
	n=read(),srand(114514);
	for(re int i=1;i<=n;++i)A[i]=read(),B[i]=read(),C[i]=read(),D[i]=read(),V.push_back((node){A[i],B[i]}),V.push_back((node){C[i],D[i]});
	sort(V.begin(),V.end()),V.resize(unique(V.begin(),V.end())-V.begin());
	for(re int i=0;i<V.size();++i)P[V[i]]=++tot,V[i].id=tot,p[tot]=V[i];
	if(!P.count((node){0,0}))V.push_back((node){0,0,tot+1}),P[(node){0,0}]=++tot,p[tot]=(node){0,0};
	rt=solve(0,inf-1,0,inf-1,V);
	for(re int i=1;i<=n;++i){
		node t1=(node){A[i],B[i]},t2=(node){C[i],D[i]};
		++w[P[t1]],++w[P[t2]];
		re int z=lca(0,inf-1,0,inf-1,t1,t2);
		tg[z]=1,w[z]-=2;
	}
	for(re int i=1;i<=tot;++i)if(fa[i])G[fa[i]].push_back(i);
	dfs(rt);for(auto z:ans)if(z.first)O+=z.second;
	printf("%d",O);
}