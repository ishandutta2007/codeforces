#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int n,a[6002],b[6002],c[6002],d[6002],f[4][4],ans,g[4][4];
inline int C3(re int x){return x*(x-1)*(x-2)/6;};
inline int C2(re int x){return x*(x-1)/2;}
inline int calc(re int A,re int B,re int C,re int D){
	C^=A,D^=B;
	if(C==0&&D==0)return 0;
	return 1;
}
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read()>>1,b[i]=read()>>1,a[i]&=1,b[i]&=1,++f[a[i]][b[i]];
	for(re int A=0;A<=1;++A)
		for(re int B=0;B<=1;++B)
			for(re int C=0;C<=1;++C)
				for(re int D=0;D<=1;++D)
					for(re int E=0;E<=1;++E)
						for(re int F=0;F<=1;++F){
							memset(g,0,sizeof(g));
							re int ss=1;
							re int s=calc(A,B,C,D)+calc(A,B,E,F)+calc(C,D,E,F);
							if(s%2==0){
								++g[A][B],++g[C][D],++g[E][F];
								for(re int i=0;i<=1;++i)for(re int j=0;j<=1;++j)
								if(g[i][j]==1)ss*=f[i][j];
								else if(g[i][j]==2)ss*=C2(f[i][j]),ss*=2;
								else if(g[i][j]==3)ss*=C3(f[i][j]),ss*=6;
								ans+=ss; 
							}
						}
	assert(ans%6==0);
	printf("%lld",ans/6);
}