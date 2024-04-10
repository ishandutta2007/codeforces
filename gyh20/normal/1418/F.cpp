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
#define ll long long
using namespace std;
inline ll read(){
	re ll t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,k,l,r,num[200002];
ll L,R;
set<int>S;
set<int>::iterator it;
inline void Ins(re int x){
	if(!num[x])S.insert(x);
	++num[x];
}
inline void Del(re int x){
	--num[x];
	if(!num[x])S.erase(x);
}
vector<int>D[200002];
int main(){
	n=read(),m=read(),L=read(),R=read(),k=max(n,m);
	for(re int i=1;i<=k;++i)for(re int j=i;j<=k;j+=i)D[j].push_back(i);
	l=m,r=m;
	for(re int i=1;i<=n;++i){
		while(1ll*i*l>=L){
			for(auto z:D[l])Ins(z);
			--l;
		}
		while(1ll*i*r>R){
			for(auto z:D[r])Del(z);
			--r;
		}re bool ia=0;
		for(auto z:D[i])if((it=S.lower_bound(z+1))!=S.end()){
			re int o=*it;
			if(1ll*i/z*o<=n){
				ia=1;re int y=r/o*o;
				printf("%d %d %d %d\n",i,y,i/z*o,y/o*z);
				break;
			}
		}
		if(!ia)puts("-1");
	}
}