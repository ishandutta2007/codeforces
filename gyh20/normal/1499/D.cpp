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
int t,n,m,A,B,C,ans,f[20000002],pw[10002];
bool vis[20000002];
char s[200002];
inline void check(re int x){
	re int dlt=C/x+B;
	if(dlt%A==0){
		dlt/=A;
		if(dlt==1){
			++ans;
			return;
		}
		ans+=pw[f[dlt]];
	}
}
signed main(){
	t=read();
	n=2e7;
	for(re int i=2;i<=n;++i)
		if(!vis[i])
		for(re int j=i;j<=n;j+=i)++f[j],vis[j]=1;
	for(re int i=pw[0]=1;i<63;++i)pw[i]=pw[i-1]<<1;
	while(t--){
		A=read(),B=read(),C=read();ans=0;
		for(re int i=1;i*i<=C;++i){
			if(C%i==0){
				check(i);
				if(i*i!=C)check(C/i);
			}
		}
		printf("%lld\n",ans);
	}
}