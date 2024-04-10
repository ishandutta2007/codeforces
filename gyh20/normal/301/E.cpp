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
int n,m,K,f[2][102][102][102],C[102][102],tmp,ans;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int main(){
	n=read(),m=read(),K=read();
	for(re int i=C[0][0]=1;i<=n;++i)
		for(re int j=C[i][0]=1;j<=i;++j)
			C[i][j]=Mod(C[i-1][j]+C[i-1][j-1]);
	f[0][0][1][1]=1,++n;
	for(re int i=0;i<=m;++i){
		re int s=0;
		for(re int j=2;j<=n;++j)
			for(re int k=0;k<=K;++k)
				add(s,f[tmp][j][0][k]),f[tmp][j][0][k]=0;
		add(ans,1ll*s*(m-i+1)%M);
		tmp^=1;
		for(re int j=i;j<=n;++j)
			for(re int k=1;k<=n-j;++k)
				for(re int l=1,x;l<=K;++l){
					if(x=f[tmp^1][j][k][l])
						for(re int t=k;t+j<=n&&l*C[t-1][k-1]<=K&&n-j-t>=t-k;++t)
							add(f[tmp][j+t][t-k][l*C[t-1][k-1]],x);
					f[tmp^1][j][k][l]=0;
				}
	}
	printf("%d",ans);
}