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
int t,n,m,a[1000002],ans,A,B,sum,mx;
char s[1000002];
signed main(){
	t=read();
	while(t--){
		n=read(),ans=0; sum=0,mx=0;
		for(re int i=1;i<=n;++i)scanf("%lld",&a[i]);
		int X;
		scanf("%lld",&X);
		for(re int i=1;i<=n;++i)a[i]-=X;
		re int o=1;ans=1;mx=0,sum=a[1];
		for(re int i=2;i<=n;++i){
			if(!o)++ans,o=i,sum=a[i],mx=0;
			else{
				if(a[i]+sum-mx>=0)mx=max(mx,sum),sum+=a[i],o=i,++ans;
				else o=0,sum=mx=0;
			}
		}
		printf("%lld\n",ans);
	}
}