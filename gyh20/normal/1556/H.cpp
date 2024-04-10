#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int A[1302],B[1302],pre[1302],S,T,n,m,fa[1302],W[1302],dis[1302],V[1302],Q[200002],hd,tl,d[1302],col[1302],k,a[52][52],lmt[52],p[1302],ta[1302],tb[1302],tv[1302];
char vis[1302],usd[1302],inq[1302];
vector<int>G[1302];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){
	x=root(x),y=root(y);
	if(x==y)++vis[x];
	else fa[x]=y,vis[y]+=vis[x];
}
inline bool ck1(){
	for(re int i=1;i<=n;++i)fa[i]=i,vis[i]=0;
	for(re int i=1;i<=m;++i)
		if(usd[i]){
			Merge(A[i],B[i]);
			if(vis[root(A[i])])return 0;
		}
	return 1;
}
inline bool ck2(){
	for(re int i=1;i<=n;++i)d[i]=0;
	for(re int i=1;i<=m;++i)
		if(usd[i]){
			++d[A[i]],++d[B[i]];
			if(d[A[i]]>lmt[A[i]]||d[B[i]]>lmt[B[i]])return 0;
		}
	return 1;
}
inline int cmp(re int x,re int y){return V[x]<V[y];}
int main(){
	n=read(),k=read(),m=0;
	for(re int i=1;i<=k;++i)lmt[i]=read();
	for(re int i=k+1;i<=n;++i)lmt[i]=114514;
	for(re int i=1;i<=n;++i)
		for(re int j=i+1;j<=n;++j)
			a[i][j]=read();
	for(re int i=1;i<=n;++i)
		for(re int j=i+1;j<=k;++j)
			A[++m]=i,B[m]=j,V[m]=a[i][j];
	for(re int i=1;i<=n;++i)
		for(re int j=max(k+1,i+1);j<=n;++j)
			A[++m]=i,B[m]=j,V[m]=a[i][j];
	int ans=1e9;
	for(re int i=1;i<=m;++i)p[i]=i;
	sort(p+min(m,11),p+m+1,cmp);
	for(re int i=1;i<=n;++i)fa[i]=i;
	re int mm=0;
	for(re int i=1;i<=m;++i)ta[i]=A[p[i]],tb[i]=B[p[i]],tv[i]=V[p[i]];
	for(re int i=1;i<=m;++i)
		if(ta[i]>k&&tb[i]>k&&i>10){
			if(root(ta[i])^root(tb[i]))A[++mm]=ta[i],B[mm]=tb[i],V[mm]=tv[i];
			fa[root(ta[i])]=root(tb[i]);
		}
		else A[++mm]=ta[i],B[mm]=tb[i],V[mm]=tv[i];
	m=mm;
	for(re int i=0;i<(1<<(min(m,10)));++i){
		S=m+1,T=m+2,memset(usd,0,sizeof(usd));
		for(re int j=0;j<10;++j)if(i&(1<<j))usd[j+1]=1;
		if(!(ck1()&&ck2()))continue;
		while(1){
			for(re int i=1;i<=T;++i)dis[i]=-1e9,inq[i]=0;dis[S]=0;
			for(re int i=1;i<=m;++i)if(usd[i])W[i]=V[i];else W[i]=-V[i];
			for(re int i=1;i<=T;++i)G[i].clear();
			ck1();ck2();
			for(re int i=11;i<=m;++i)
				if(!usd[i]){
					usd[i]=1;
					if(root(A[i])^root(B[i]))G[S].push_back(i);
					if(d[A[i]]+1<=lmt[A[i]]&&d[B[i]]+1<=lmt[B[i]])G[i].push_back(T);
					usd[i]=0;
				}
			for(re int i=11;i<=m;++i)
				if(usd[i]){
					usd[i]=0;ck1();
					for(re int j=11;j<=m;++j)
						if((i^j)&&(!usd[j])){
							re int x=root(A[j]),y=root(B[j]);
							if(x^y)G[i].push_back(j);
						}--d[A[i]],--d[B[i]];
					for(re int j=11;j<=m;++j)	
						if((i^j)&&(!usd[j]))
							if(d[A[j]]+1<=lmt[A[j]]&&d[B[j]]+1<=lmt[B[j]])G[j].push_back(i);
					usd[i]=1,++d[A[i]],++d[B[i]];
				}
			Q[hd=tl=100000]=S,inq[S]=1;
			while(hd<=tl){
				re int x=Q[hd++];inq[x]=0;
				for(auto i:G[x])if(dis[x]+W[i]>dis[i]){dis[i]=dis[x]+W[i],pre[i]=x;if(!inq[i])(dis[i]<dis[Q[hd]]?Q[--hd]=i:Q[++tl]=i),inq[i]=1;}
			}
			if(dis[T]==-1000000000)break;
			re int x=T;
			while(x^S)usd[x]^=1,x=pre[x];
		}
		re int s=0,nn=0;
		for(re int j=1;j<=m;++j)if(usd[j])s+=V[j],++nn;
		if(nn==n-1)ans=min(ans,s);
	}printf("%d",ans);
}