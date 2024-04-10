#include<bits/stdc++.h>
#define re register
using namespace std;
char rbuf[20000002];
int pt=-1;
inline int read(){
	re int t=0;re char v=rbuf[++pt];
	while(v<'0')v=rbuf[++pt];
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=rbuf[++pt];
	return t;
}
vector<int>V[200002],bl[200002];
int n,m,k,a[200002],f[200002],g[200002],X[200002],px[200002],py[200002],S[200002],SSS,num,Ans[200002],ANS,SZ[200002],tot,N[3002][16384],IA,ss[200002],KKKK;
inline void build(re int x){
	if(V[x].size()>4000){
		SZ[x]=sqrt(V[x].size()),bl[x].resize(V[x].size());
		for(re int i=0;i<V[x].size();++i)bl[x][i]=tot+i/SZ[x];
		tot=bl[x][V[x].size()-1]+1;
		re int s=0;
		for(re int i=0;i<V[x].size();++i){
			S[bl[x][i]]^=V[x][i];
			if(i&&bl[x][i]!=bl[x][i-1])s=0;
			s^=V[x][i],++N[bl[x][i]][s];
		}
	}
	re int s=0;
	for(re int i=0;i<V[x].size();++i)s^=V[x][i],Ans[x]+=(s==0);
	IA+=s>0,ss[x]=s,ANS+=Ans[x];
}
inline void cg(re int x,re int y,re int z){
	ANS-=Ans[x],Ans[x]=0,IA-=ss[x]>0;
	if(V[x].size()<=4000){
		V[x][y]=z;++KKKK;
		re int s=0;
		for(re int i=0;i<V[x].size();++i)s^=V[x][i],Ans[x]+=(s==0);
		ss[x]=s,IA+=ss[x]>0;
	}
	else{
		re int s=0,o=y,Bl=bl[x][y];
		while(o&&bl[x][o-1]==Bl)--o,s^=V[x][o];
		for(re int i=y;i<V[x].size()&&bl[x][i]==Bl;++i)s^=V[x][i],--N[Bl][s],++N[Bl][s^V[x][y]^z];
		S[bl[x][y]]^=V[x][y]^z,V[x][y]=z,s=0;
		for(re int i=bl[x][0];i<=bl[x][V[x].size()-1];++i)Ans[x]+=N[i][s],s^=S[i];
		ss[x]=s,IA+=ss[x]>0;
	}
	ANS+=Ans[x];
} 
inline char nc(){
	while(rbuf[pt+1]!='a'&&rbuf[pt+1]!='b')++pt;
	return rbuf[++pt];
}
int main(){
	fread(rbuf,1,20000000,stdin),n=read(),k=read(),m=read();
	for(re int i=1;i<=n;++i)f[i]=read();
	for(re int i=1;i<=n;++i)g[i]=read();
	for(re int i=1;i<=n;++i)X[i]=f[i]^g[i];
	++n;
	for(re int i=n;i;--i)X[i]^=X[i-1];
	for(re int i=1;i<=n;++i)V[i%k].push_back(X[i]),px[i]=i%k,py[i]=V[i%k].size()-1;
	for(re int i=0;i<k;++i)build(i);
	if(IA)puts("-1");
	else printf("%d\n",n-ANS);
	while(m--){
		char s=nc();re int x,y;
		x=read(),y=read();
		if(s=='a')f[x]=y;
		else g[x]=y;
		X[x]=f[x]^g[x]^f[x-1]^g[x-1],X[x+1]=f[x]^g[x]^f[x+1]^g[x+1];
		cg(px[x],py[x],X[x]),cg(px[x+1],py[x+1],X[x+1]);
		if(IA)puts("-1");
		else printf("%d\n",n-ANS);
	}
}