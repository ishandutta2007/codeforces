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
int n,a[100002],p[100002],pos[100002],ia,G;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int main(){
	n=read(),srand(time(0));
	for(re int i=1;i<=n;++i)a[i]=read(),p[i]=i,G=__gcd(a[i],G);
	if(G>1)puts("NO"),exit(0);
	for(re int i=1;i<=100;++i){
		for(re int j=2;j<=n;++j)swap(p[j],p[((rand()<<15)|rand())%(j-1)+1]);
		re int g1=a[p[1]],la=1,g2=0;pos[p[1]]=1;
		for(re int j=2;j<=n/2+1&&g1>1;++j){
			re int ll=g1;
			g1=__gcd(g1,a[p[j]]);
			if(ll^g1)pos[p[j]]=1;
			else pos[p[j]]=2,g2=__gcd(g2,a[p[j]]);
			la=j;
		}
		for(re int j=la+1;j<=n;++j)g2=__gcd(g2,a[p[j]]),pos[p[j]]=2;
		if(g2==1&&g1==1){ia=1;break;}
		if(la==n)break;
	}
	if(ia){
		puts("YES");
		for(re int i=1;i<=n;++i)printf("%d ",pos[i]);
	}
	else puts("NO");
}