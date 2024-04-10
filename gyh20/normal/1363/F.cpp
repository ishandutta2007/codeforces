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
int n,f[2][20002],p1[20002],p2[20002],tmp;
char a[20002],b[20002];
vector<int>V[20002],ttmp;
inline void gmn(re int &x,re int y){y<x&&(x=y);}
int main(){
//	freopen("fs8.in","r",stdin);
int t=read();
while(t--){
	n=read();
	scanf("%s%s",a+1,b+1);
	for(re int i=1;i<='z';++i)V[i].clear();
	for(re int i=1;i<=n;++i)V[b[i]].push_back(i);
	for(re int i=1;i<='z';++i)V[i].push_back(n+1);
	memset(f,127,sizeof(f)),f[0][0]=0,memset(p1,0,sizeof(p1)),tmp=0;
	for(re int i=0;i<n;++i,tmp^=1){
		++p1[a[i+1]],memset(f[tmp^1],127,sizeof(f[tmp^1])),memset(p2,0,sizeof(p2));
		re int x=0,pos=0;
		int *F=f[tmp],*G=f[tmp^1];
		ttmp=V[a[i+1]];
		for(re int j=1;j<i;++j)++p2[b[j]];
		for(re int j=i;j<=n;++j){
			++p2[b[j]];
			if(F[j]<114514){
				while(ttmp[pos]<=j)++pos;
				if(p1[a[i+1]]<=p2[a[i+1]])gmn(G[j],F[j]+1);
				gmn(G[ttmp[pos]],F[j]);
			}
		}
	}
	re int ans=114514;
	for(re int i=0;i<=n;++i)gmn(ans,f[tmp][i]);
	printf("%d\n",ans==114514?-1:ans);
}
}