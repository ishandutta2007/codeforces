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
	n=read();ans=1e18;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		b[i]=0;re int sum=0;
		for(re int j=i-1;j;--j){
			re int dlt=b[j+1]/a[j]+1;
			sum+=dlt,b[j]=a[j]*dlt; 
		}
		for(re int j=i+1;j<=n;++j){
			re int dlt=b[j-1]/a[j]+1;
			sum+=dlt,b[j]=a[j]*dlt; 
		}ans=min(ans,sum);
	}printf("%lld",ans);
}