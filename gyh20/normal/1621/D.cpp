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
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,ans,a[100002],f[502][502];
signed main(){
	t=read();
	while(t--){
		n=read();ans=0;
		for(re int i=1;i<=n+n;++i)
			for(re int j=1;j<=n+n;++j)
				f[i][j]=read();
		for(re int i=n+1;i<=n+n;++i)
			for(re int j=n+1;j<=n+n;++j)
				ans+=f[i][j];
		re int s=1e18;
		s=min(s,f[1][n+1]),s=min(s,f[n+1][1]),s=min(s,f[n][n+1]),s=min(s,f[n+1][n]),s=min(s,f[n][n+n]),s=min(s,f[n+n][n]);
		s=min(s,f[n+n][1]),s=min(s,f[1][n+n]);
		printf("%lld\n",s+ans);
	}
}