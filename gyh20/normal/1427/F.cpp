#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,stkx[1202],stky[1202],L[1202],R[1202],tp,ir[1202];
char v[1202],u[1202][1202],usd[1202],o[1202];
inline bool ck(re int x){
	for(re int i=1;i<=m;++i)if(u[i][x]&&(!usd[i]))return 0;
	return 1;
}
int main(){
	n=read()*6;
	for(re int i=1;i+i<=n;++i)v[read()]=1;
	for(re int i=1;i<=n;++i){
		if(tp&&v[i]==v[stkx[tp]])++stky[tp];
		else stkx[++tp]=i,stky[tp]=1;
		if(stky[tp]==3)L[++m]=stkx[tp],R[m]=i,--tp;
	}
	for(re int i=1;i<=m;++i){
		re int num=0;
		for(re int j=1;j<=m;++j)if(L[j]<L[i]&&R[j]>R[i])++num,u[i][j]=1;
		if(!num)ir[i]=1;
	}
	for(re int i=1;3*i<=n;++i){
		re int pos=0,pp=0;
		for(re int j=1;j<=m;++j)if(!usd[j]&&v[L[j]]==(i&1)&&ck(j)){if(!pos||ir[j]<ir[pos])pos=j;}
		usd[pos]=1;
		for(re int j=L[pos];j<=R[pos];++j)if(!o[j]&&v[j]==v[L[pos]])o[j]=1,printf("%d ",j);puts("");
	}
}