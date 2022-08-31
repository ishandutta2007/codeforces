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
bitset<128>tmp1,tmp;
int n,p[8][8],iv,X,ans;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int main(){
	n=read(),iv=ksm(100,M-2);
	for(re int i=0;i<n;++i)
		for(re int j=0;j<n;++j)
			p[i][j]=1ll*read()*iv%M;
	tmp[0]=1;
	V[0][tmp]=1;
	for(re int i=0;i<n;++i)
		for(auto it=V[i].begin();it!=V[i].end();++it){
			tmp1=it->first,X=it->second;
			for(re int j=0;j<(1<<n);++j){
				tmp=tmp1;
				re int s=X;
				for(re int k=0;k<n;++k)if(j&(1<<k))s=1ll*s*p[k][i]%M;else s=1ll*s*(M+1-p[k][i])%M;
				for(re int k=0;k<n;++k)
					if(j&(1<<k))
						for(re int ii=0;ii<(1<<n);++ii)if(tmp1[ii])tmp[ii|(1<<k)]=1;
				add(V[i+1][tmp],s);
			}
		}
	for(auto it=V[n].begin();it!=V[n].end();++it)if((it->first)[(1<<n)-1])add(ans,it->second);
	printf("%d",ans);
}