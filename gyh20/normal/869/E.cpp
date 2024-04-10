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
#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[2502][2502],L1[100002],R1[100002],L2[100002],R2[100002],q;
char usd[100002];
inline int chk(re int x,re int xx,re int yy){if(usd[x])return 0;return xx<=R1[x]&&yy>=L2[x]&&yy<=R2[x];}
inline int find(re int x,re int y){
	re int X=x,Y=y;
	while(!chk(a[x][y],X,Y))--x;
	return a[x][y];
}
int main(){
	n=read(),m=read(),q=read(),usd[0]=1;
	for(re int i=1;i<=m;++i)a[1][i]=q+1;
	L1[q+1]=1,R1[q+1]=n,L2[q+1]=1,R2[q+1]=m;
	for(re int ii=1;ii<=q;++ii){
		re int o=read(),l1=read(),l2=read(),r1=read(),r2=read();
		if(o==1){
			L1[ii]=l1,R1[ii]=r1,L2[ii]=l2,R2[ii]=r2;
			for(re int i=l2;i<=r2;++i)a[l1][i]=ii;
		}
		else if(o==2)usd[a[l1][l2]]=1;
		else{
			re int x=find(l1,l2),y=find(r1,r2);
			if(x==y)puts("Yes");
			else puts("No");
		}
	}
}