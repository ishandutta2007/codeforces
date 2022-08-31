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
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,a[100002][6],t,ans,w[100002],p[100002],b[100002][6],W[100002],X,P[100002],nn;
char s[1000002];
bitset<25002>B[100002],tmp;
inline bool cmp(re int x,re int y){return W[x]<W[y];}
inline bool cmp1(re int x,re int y){return a[x][X]<a[y][X];}
map<int,vector<int> >V;
signed main(){
	n=read(),m=read();ans=2e9;++ans;
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=m;++j)b[i][j]=read();
		W[i]=read(),p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=m;++j)a[i][j]=b[p[i]][j];
		w[i]=W[p[i]];
	}
	for(re int i=1;i<=n;++i)B[i].set(),B[i][0]=0;
	V.clear();
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=m;++j)V[a[i][j]].push_back(i);
	}
	tmp.set();
	for(auto &o:V){
		vector<int>T=o.second;
		for(re int j=0;j<T.size();++j)if(T[j]<=25000)tmp[T[j]]=0;
		for(re int j=0;j<T.size();++j)B[T[j]]&=tmp;
		for(re int j=0;j<T.size();++j)if(T[j]<=25000)tmp[T[j]]=1;
	}
	for(re int i=1;i<=n;++i){
		re int x=B[i]._Find_first();
		if(x<=min(25000,n))ans=min(ans,w[i]+w[x]);
	}
	if(n>25000){
	for(re int i=1;i<=n;++i)B[i].set(),B[i][0]=0;
		tmp.set();
		for(auto &o:V){
			vector<int>T=o.second;
			for(re int j=0;j<T.size();++j)if(T[j]>25000&&T[j]<=50000)tmp[T[j]-25000]=0;
			for(re int j=0;j<T.size();++j)B[T[j]]&=tmp;
			for(re int j=0;j<T.size();++j)if(T[j]>25000&&T[j]<=50000)tmp[T[j]-25000]=1;
		}
		for(re int i=1;i<=n;++i){
			re int x=B[i]._Find_first();
			if(x<=25000&&x+25000<=n)ans=min(ans,w[i]+w[x+25000]);
		}
	}
	if(n>50000){
	for(re int i=1;i<=n;++i)B[i].set(),B[i][0]=0;
		tmp.set();
		for(auto &o:V){
			vector<int>T=o.second;
			for(re int j=0;j<T.size();++j)if(T[j]>50000&&T[j]<=75000)tmp[T[j]-50000]=0;
			for(re int j=0;j<T.size();++j)B[T[j]]&=tmp;
			for(re int j=0;j<T.size();++j)if(T[j]>50000&&T[j]<=75000)tmp[T[j]-50000]=1;
		}
		for(re int i=1;i<=n;++i){
			re int x=B[i]._Find_first();
			if(x<=25000&&x+50000<=n)ans=min(ans,w[i]+w[x+50000]);
		}
	}
	if(n>75000){
	for(re int i=1;i<=n;++i)B[i].set(),B[i][0]=0;
		tmp.set();
		for(auto &o:V){
			vector<int>T=o.second;
			for(re int j=0;j<T.size();++j)if(T[j]>75000)tmp[T[j]-75000]=0;
			for(re int j=0;j<T.size();++j)B[T[j]]&=tmp;
			for(re int j=0;j<T.size();++j)if(T[j]>75000)tmp[T[j]-75000]=1;
		}
		for(re int i=1;i<=n;++i){
			re int x=B[i]._Find_first();
			if(x+75000<=n)ans=min(ans,w[i]+w[x+75000]);
		}
	}
	if(ans>2000000000){
		puts("-1");
		return 0;
	}
	printf("%d",ans);
}