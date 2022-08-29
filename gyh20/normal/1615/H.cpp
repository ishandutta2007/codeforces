#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
bool cut[1005];
struct Flow{
	int n,head[1005],cnt,gap[1005],dis[1005],S,T,q[1000002],hd,tl,m,v[1005];
	struct edge{int to,next,w;}e[2000002];
	inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt,e[++cnt]=(edge){x,head[y],0},head[y]=cnt;}
	inline int dfs(re int x,re int y){
		if(x==T)return y;
		re int tmp=0;
		for(re int i=head[x];i;i=e[i].next)
			if(e[i].w&&dis[x]==dis[e[i].to]+1){
				re int dlt=dfs(e[i].to,min(y,e[i].w));
				y-=dlt,e[i].w-=dlt,e[i^1].w+=dlt,tmp+=dlt;
				if(!y||dis[S]==T)return tmp;
			}
		if(!(--gap[dis[x]]))dis[S]=T;
		++gap[++dis[x]];
		return tmp;
	}
	inline int SAP(){
		dis[q[hd=tl=1]=T]=0,v[T]=1;
		while(hd<=tl){
			re int x=q[hd++];
			for(re int i=head[x];i;i=e[i].next)if(!v[e[i].to])v[e[i].to]=1,++gap[dis[e[i].to]=dis[x]+1],q[++tl]=e[i].to;
		}
		re int ans=0;
		while(dis[S]<T)ans+=dfs(S,1e18);
		return ans;
	}
	inline void dfs(re int x){
		if(cut[x])return;
		cut[x]=1;
		for(re int i=head[x];i;i=e[i].next)if(e[i].w)dfs(e[i].to); 
	}
	inline void calc(re vector<int>&w,re vector<int>&A,re vector<int>&B){
		n=w.size(),m=A.size(),cnt=1,S=n,T=S+1;
		for(re int i=0;i<=T;++i)v[i]=dis[i]=gap[i]=head[i]=cut[i]=0;
		re int sum=0;
		for(re int i=0;i<n;++i)if(w[i]>0)add(S,i,w[i]),sum+=w[i];else if(w[i]<0)add(i,T,-w[i]);
		for(re int i=0;i<m;++i)add(A[i],B[i],1e18);
		re int sss=sum-SAP();
		dfs(S);
	}
}G;
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline int Abs(re int x){
	return x>0?x:-x;
}
int t,n,m,a[1000002],ans,F[10002],pos[1002];
inline void solve(vector<int>&P,vector<int>&L,vector<int>&R,re int l,re int r){
	if(l==r){
		for(re int i=0;i<P.size();++i)F[P[i]]=l;
		return;
	}
	if(P.size()==0)return;
	re int mid=l+r>>1;
	vector<int>WW,AA,BB;
	for(re int i=0;i<P.size();++i)WW.push_back(a[P[i]]>mid?1:-1),pos[P[i]]=i;
	for(re int i=0;i<L.size();++i)AA.push_back(pos[L[i]]);
	for(re int i=0;i<R.size();++i)BB.push_back(pos[R[i]]);
	G.calc(WW,AA,BB);
	vector<int>nl,nr,X1,Y1,X2,Y2;
	for(re int i=0;i<P.size();++i)
		if(!cut[i])nl.push_back(P[i]);
		else nr.push_back(P[i]);
	for(re int i=0;i<L.size();++i)
		if(cut[pos[L[i]]]==cut[pos[R[i]]]&&cut[pos[L[i]]]==0)
			X1.push_back(L[i]),Y1.push_back(R[i]);
	for(re int i=0;i<L.size();++i)
		if(cut[pos[L[i]]]==cut[pos[R[i]]]&&cut[pos[L[i]]]==1)
			X2.push_back(L[i]),Y2.push_back(R[i]);
	solve(nl,X1,Y1,l,mid);
	solve(nr,X2,Y2,mid+1,r);
}
signed main(){
	n=read(),m=read();
	vector<int>L,R,P;
	for(re int i=1;i<=n;++i)a[i]=read(),P.push_back(i);
	for(re int i=1;i<=m;++i)L.push_back(read()),R.push_back(read());
	solve(P,L,R,-1e15,1e15);
	for(re int i=1;i<=n;++i)printf("%lld ",F[i]);
}