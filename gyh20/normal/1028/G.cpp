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
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int f[6][10002],n;
inline void Get(re int i,re int j){
	vector<int>tmp;
	if(i==1){
		for(re int x=j;x<j+min(j,10000ll);++x)tmp.push_back(x);
		printf("%u ",tmp.size());
		for(re int i=0;i<tmp.size();++i)printf("%lld ",tmp[i]);puts("");fflush(stdout);
		return;
	}
	re int x=j+f[i-1][min(j,10000ll)]+2;
	for(re int k=1;k<=min(10000ll,j);++k)tmp.push_back(x-1),x+=f[i-1][min(x,10000ll)],x+=2;
	printf("%u ",tmp.size());
	for(re int i=0;i<tmp.size();++i)printf("%lld ",tmp[i]);puts("");fflush(stdout);
	re int s=read();
	if(s<=-1)return;
	if(s==0)Get(i-1,j);
	else Get(i-1,tmp[s-1]+1);
}
signed main(){
	for(re int i=1;i<=10000;++i)f[1][i]=i-1;
	for(re int i=2;i<=5;++i){
		for(re int j=1;j<=(i<5?10000:1);++j){
			re int x=j+f[i-1][j]+2;
			for(re int k=1;k<=j;++k)x+=f[i-1][min(x,10000ll)],x+=2;
			f[i][j]=x-2-j;
		}
	}
	Get(5,1);
}