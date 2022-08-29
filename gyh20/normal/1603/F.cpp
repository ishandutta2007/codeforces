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
inline int Mod(re int x){return x>=M?x-M:x;}
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int t,n,k,X,pw[10000002],ans,inv[10000002];
int main(){
	t=read(),n=1e7;
	for(re int i=pw[0]=1;i<=n;++i)pw[i]=Mod(pw[i-1]+pw[i-1]),inv[i]=ksm(M+1-pw[i],M-2);
	while(t--){
		n=read(),k=read(),X=read();
		if(X==0){
			if(n>k){puts("0");continue;}
			re int s=1;
			for(re int i=0;i<n;++i)s=1ll*s*(pw[k]-pw[i]+M)%M;
			printf("%d\n",s);
		}
		else{
			ans=0;re int s=1,iv=ksm(pw[k]-1,M-2),tmp=ksm(2,n);
			for(re int i=0;i<=k&&i<=n;++i){
				re int o=pw[i]-1;
				re int P=1ll*(pw[i]-1)*iv%M;
				add(ans,1ll*s*(M+1-P)%M);s=1ll*s*(pw[k]-pw[i]+M)%M*(M+1-tmp)%M*inv[i+1]%M;
				if(tmp&1)tmp=tmp+M>>1;
				else tmp>>=1;
			}
			printf("%d\n",ans);
		}
	}
}