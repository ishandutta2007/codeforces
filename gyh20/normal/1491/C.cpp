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
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],val[500002],tmp;
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),val[i]=0;
		ans=0;tmp=0;
		for(re int i=1;i<=n;++i){
			tmp=val[i];
			ans+=max(0ll,a[i]-1-tmp);
			
			if(a[i]-tmp<1){
				val[i+1]+=tmp-a[i]+1;
				for(re int j=i+2;j<=min(n,i+a[i]);++j)++val[j];
			}
			else{
				for(re int j=i+2;j<=min(n,i+a[i]);++j)++val[j];
				
			}
		}
		printf("%lld\n",ans);
	}
}