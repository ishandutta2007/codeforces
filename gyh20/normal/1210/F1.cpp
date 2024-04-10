#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
unordered_map<bitset<128>,int>V[8];
bitset<128>tmp1,tmp,T[8];
int n,p[8][8],iv,X,ans,pos,pp[128],tot;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline void dfs(re int x,re int s,bitset<128>tmp){
	if(x==n){
		add(V[pos+1][tmp],s);
		return;
	}
	dfs(x+1,1ll*s*(M+1-p[x][pos])%M,tmp);
	tmp|=T[x];
	dfs(x+1,1ll*s*p[x][pos]%M,tmp);
}
int main(){
	n=read(),iv=ksm(100,M-2);
	for(re int i=0;i<n;++i)
		for(re int j=0;j<n;++j)
			p[i][j]=1ll*read()*iv%M;
	tmp[0]=1;
	V[0][tmp]=1;
	for(re int i=0;i<n;++i){
		for(auto it=V[i].begin();it!=V[i].end();++it){
			pos=i;
			tmp1=it->first,X=it->second;tot=0;
			for(re int k=0;k<n;++k){
				T[k].reset();
				for(re int j=0;j<(1<<n);++j)if(tmp1[j])T[k][j|(1<<k)]=1;
			}
			dfs(0,X,tmp1);
		}
	}
	for(auto it=V[n].begin();it!=V[n].end();++it)if((it->first)[(1<<n)-1])add(ans,it->second);
	printf("%d",ans);
}