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
int n,m,p[1000002],sum,ans[1000002],O;
inline int Find(re int x,re int y){
	if(x<=O&&y<=O){
		for(re int i=0;i<=n;i+=y)if((n-i)%x==0)return i;
	}
	else{
		if(y>x){
			for(re int i=0;i<=n;i+=y)if((n-i)%x==0)return i;
		}
		else{
			re int o=-1;
			for(re int i=0;i<=n;i+=x)if((n-i)%y==0)o=n-i;
			return o;
		}
	}return -1;
}
signed main(){
	n=read(),O=sqrt(n);
	for(re int i=1;i<=n;++i){
		re int x=read(),y=read();
		p[i]=y-x;
		sum+=x;
	}
	sort(p+1,p+n+1),reverse(p+1,p+n+1);
	ans[0]=sum;
	for(re int i=1;i<=n;++i)ans[i]=ans[i-1]+p[i];
	re int Mx=0;
	for(re int i=1;i<=n;++i)if(ans[i]>ans[Mx])Mx=i;
	m=read();
	while(m--){
		re int x=read(),y=read(),s=-1,G=__gcd(x,y);
		if(n%G)puts("-1");
		else{
			re int z=Find(x,y);
			if(z==-1)puts("-1");
			else{
				re int V=x*y/G,dlt=max(0ll,(Mx-z)/V);
				z+=dlt*V;
				for(re int i=z;i<=z+V&&i<=n;i+=V)s=max(s,ans[i]);
				printf("%lld\n",s);
			}
		}
	}
}