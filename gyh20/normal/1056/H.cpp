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
#define ull unsigned long long
using namespace std;
const int Mxdt=1000000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int t,n,q,pos[300002],m,stk[1000002],tp;
vector<int>G[300002];
struct node{
	int x,y;
	bool operator <(const node A)const{return x<A.x;}
};
vector<node>Q[300002];
int main(){
	t=read();
	while(t--){
		n=read(),q=read();re bool ia=1;
		for(re int i=1;i<=n;++i)pos[i]=-1,Q[i].clear();
		for(re int i=1;i<=q;++i){
			G[i].resize(read());
			for(re int j=0;j<G[i].size();++j)G[i][j]=read();
		}
		for(re int i=1;i<=q&&ia;++i){
			if(G[i].size()>200){
				for(re int j=0;j<G[i].size();++j)pos[G[i][j]]=j;
				for(re int j=1;j<=q&&ia;++j)
					if(j^i){
						re int mx=-1;
						for(re int k=G[j].size()-1;~k;--k){
							if(pos[G[j][k]]!=-1&&k+1<G[j].size()&&pos[G[j][k]]+1!=pos[G[j][k+1]]&&mx>pos[G[j][k]])ia=0;
							mx=max(mx,pos[G[j][k]]);
						}
					}
				for(re int j=0;j<G[i].size();++j)pos[G[i][j]]=-1;
			}
			else{
				for(re int j=0;j<G[i].size();++j)
					for(re int k=j+1;k<G[i].size();++k)
						Q[G[i][j]].push_back((node){G[i][k],G[i][j+1]});
			}
		}
		for(re int i=1;i<=n;++i)pos[i]=0;
		for(re int i=1;i<=n&&ia;++i){
			for(auto z:Q[i]){
				if(pos[z.x])ia&=pos[z.x]==z.y;
				pos[z.x]=z.y;
			}
			for(auto z:Q[i])pos[z.x]=0;
		}
		puts(ia?"Robot":"Human");
	}
}