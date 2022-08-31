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
int n,m,f[1000002],p[6],K,g[1000002];
inline int calc(re int x){
	re int s=0;
	for(re int i=0;i<6;++i){
		re int y=x%10;
		if(y%3==0)s+=y/3*p[i];
		x/=10;
	}return s;
} 
signed main(){
	K=read()-1;
	memset(f,-1,sizeof(f)),f[0]=0,memset(g,-1,sizeof(g));
	for(re int i=0;i<6;++i)p[i]=read();
	for(re int i=5;~i;--i){
		re int pw=3;
		for(re int k=1;k<=i;++k)pw*=10;
		re int tmp=min(1000000/pw,K*3); 
		for(re int j=0;(1<<j)<=tmp;++j){
			for(re int k=1000000-(1<<j)*pw;k>=0;--k)
				if(~f[k])
					f[(1<<j)*pw+k]=max(f[(1<<j)*pw+k],f[k]+(1<<j)*p[i]);
			tmp-=1<<j;
		}
		re int j=tmp;
		for(re int k=1000000-j*pw;k>=0;--k)
			if(~f[k])
				f[j*pw+k]=max(f[j*pw+k],f[k]+j*p[i]);
	}
	m=read();
	int xx=read(),ans=0;
	for(re int i=0;i<=xx;++i)if(~f[i]&&i<=xx)ans=max(ans,f[i]+calc(xx-i));
	printf("%lld",ans);
}