#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,k,A[1000002],B[1000002],p[22],F[1<<20],G[1<<20],pos;
char s[22],t[22];
inline int Get(char*c){
	re int s=0;
	for(re int i=1;i<=k;++i)if(c[i]=='1')s+=1<<p[i]-1;
	return s;
}
int main(){
	memset(F,0x3f,sizeof(F)),n=read(),m=read(),k=read(),scanf("%s%s",s+1,t+1);
	for(re int i=1;i<=n;++i)A[i]=read(),B[i]=read();
	for(re int i=1;i<=k;++i)p[i]=i;G[Get(t)]=n+1;re int z1=Get(s),z2=Get(t);
	for(re int i=n;i;--i){
		swap(p[A[i]],p[B[i]]);
		re int x=Get(s),y=Get(t);
		F[x]=min(F[x],i),G[y]=max(G[y],i);
	}
	for(re int i=(1<<k)-1;~i;--i)
		for(re int j=0;j<k;++j)
			if(i&(1<<j))
				F[i^(1<<j)]=min(F[i^(1<<j)],F[i]),G[i^(1<<j)]=max(G[i^(1<<j)],G[i]);
	for(re int i=0;i<(1<<k);++i)if(G[i]-F[i]>=m&&__builtin_popcount(i)>__builtin_popcount(pos))pos=i;
	printf("%d\n",(k+__builtin_popcount(pos)-__builtin_popcount(z1)-__builtin_popcount(z2))+__builtin_popcount(pos));
	printf("%d %d",F[pos],G[pos]-1);
}