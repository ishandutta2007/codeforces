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
int n,k,q,m,tot,a[22][100002];
char v[22];
char s[1000002];
bitset<4096>B[100022];
int main(){
	n=read(),k=read(),q=read(),tot=k;
	for(re int i=1;i<=k;++i)for(re int j=1;j<=n;++j)a[i][j]=read();
	for(re int i=0;i<(1<<k);++i){
		for(re int j=0;j<k;++j)
			B[j+1][i]=(i>>j)&1;
	}
	while(q--){
		re int o=read(),x=read(),y=read();
		if(o==1)++tot,B[tot]=B[x]|B[y];
		else if(o==2)++tot,B[tot]=B[x]&B[y];
		else{
			memset(v,0,sizeof(v));re int zt=0;
			for(re int i=1;i<=k;++i){
				re int mx=0;
				for(re int j=1;j<=k;++j)if(!v[j]&&a[j][y]>=a[mx][y])mx=j;
				v[mx]=1,zt|=1<<mx-1;
				if(B[x][zt]){printf("%d\n",a[mx][y]);break;}
			}
		}
	}
}