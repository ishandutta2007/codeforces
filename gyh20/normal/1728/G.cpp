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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int D,n,m,P[500002],Q[500002],H[500002],T[22][22],I[500002],F[1<<18],S[500002],D1[500002],D2[500002];
int main(){
	D=read(),n=read(),m=read();
	for(re int i=0;i<=D+1;++i)I[i]=ksm(i,M-2);
	for(re int i=1;i<=n;++i)P[i]=read();
	for(re int i=1;i<=m;++i)Q[i]=read();
	sort(Q+1,Q+m+1);Q[0]=-1e9;
	for(re int i=0;i<=m;++i)
		for(re int j=i+1;j<=m;++j){
			T[i][j]=1;
			for(re int k=1;k<=n;++k)
				if(P[k]>=Q[i]){
					if(i)T[i][j]=1ll*T[i][j]*I[P[k]-Q[i]]%M;
					else T[i][j]=1ll*T[i][j]*I[D+1]%M;
					T[i][j]=1ll*T[i][j]*min(P[k]-Q[i],abs(Q[j]-P[k]))%M;
				}
		}
	F[0]=ksm(D+1,n),add(D1[1],1ll*F[0]*(D+1)%M);
	for(re int i=1;i<(1<<m);++i){
		re int lst0=-1,lst1=-1;
		for(re int j=0;j<m;++j)if(i&(1<<j))lst1=lst0,lst0=j;
		++lst0,++lst1;
		F[i]=1ll*(M-F[i^(1<<lst0-1)])*T[lst1][lst0]%M; 
		re int lst=-1;
		for(re int j=0;j<m;++j)
			if(i&(1<<j)){
				if(lst==-1)add(D1[1],1ll*F[i]*(Q[j+1]-1)%M),add(D2[1],M-F[i]),add(D2[Q[j+1]],F[i]);
				else{
					add(D2[Q[lst+1]],F[i]);
					add(D2[Q[lst+1]+Q[j+1]>>1],M-F[i]),add(D2[Q[lst+1]+Q[j+1]+1>>1],M-F[i]);
					add(D2[Q[j+1]],F[i]);
				}
				lst=j;
			}
		add(D2[Q[lst+1]],F[i]);
	}
	for(re int i=1;i<=D;++i){
		add(D1[i],D1[i-1]),add(D2[i],D2[i-1]);
		add(D1[i],D2[i-1]);
	}
	int q=read();
	while(q--)printf("%d\n",D1[read()]);
	
}