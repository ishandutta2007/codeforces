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
int t,n,m,a[1000002],ans,A,B,b[1000002];
char s[1000002];
signed main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		re int s=1;
		
		for(re int i=1;i<=n;++i){
			a[i]=read();
			while(a[i]%2==0)a[i]/=2,s*=2;
		}
		sort(a+1,a+n+1);
		for(re int i=1;i<n;++i){
			ans+=a[i]; 
		}
		printf("%lld\n",ans+a[n]*s);
	}
}