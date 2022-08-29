#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,f[202][202],g[202][202],X[202],Y[202];
inline int Abs(re int x){return x>0?x:-x;}
inline bool ck(re int x){
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	for(re int i=n;i;--i)
		for(re int j=i+2;j<=n;++j)
			for(re int k=i+1;k<j;++k){
				re int nf=f[i][k]+f[k][j],ng=g[i][k]+g[k][j]+Abs((Y[j]-Y[k])*(X[k]-X[i])-(Y[k]-Y[i])*(X[j]-X[k]));
				if(ng>=x)++nf,ng=0;
				if(nf>f[i][j]||(nf==f[i][j]&&ng>g[i][j]))f[i][j]=nf,g[i][j]=ng;
			}
	return f[1][n]>m;
}
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)X[i]=read(),Y[i]=read();
	re int l=0,r=8e16,pos=0;
	while(l<=r){
		re int mid=l+r>>1;
		if(ck(mid))pos=mid,l=mid+1; 
		else r=mid-1;
	}
	printf("%lld",pos);
}