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
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002];
inline int gcd(re int x,re int y){return y?gcd(y,x%y):x;}
inline bool check(re int x){
	re int y=x,s=0;
	while(x)s+=x%10,x/=10;
	if(gcd(y,s)>1)return 1;
	return 0;
}
signed main(){
	t=read();a[0]=-1;
	for(re int i=1;i<=1000000;++i)a[i]=a[i>>1]+1;
	while(t--){
		n=read(),ans=0,m=read();
		for(re int i=0;i<=20;++i)b[i]=0;
		for(re int i=1;i<=n;++i)++b[a[read()]];
		while(n){
			re int s=m;
			for(re int i=20;~i;--i){
				while(s>=(1<<i)&&b[i])s-=(1<<i),--b[i],--n;
			}
			++ans;
		}
		printf("%lld\n",ans);
	}
}