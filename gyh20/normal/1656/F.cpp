#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
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
int t,n,m,a[1000002],ans,A,B,bl[1000002],pos[1000002];
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		re int s=0;
		for(re int i=1;i<=n;++i){
			s+=a[i];
			if(a[i]<0)bl[i]=n;
			else bl[i]=1;
		}
		
		if(s+a[n]*(n-2)<0||s+a[1]*(n-2)>0)puts("INF");
		else{
			if(n==2){
				printf("%lld\n",a[1]*a[n]);
				continue;
			}
			s=0;
			for(re int i=1;i<n;++i)s+=a[i]*a[n];
			re int dlt=0;
			for(re int i=1;i<=n;++i)dlt+=a[i];
			dlt+=(n-2)*a[n];
			int num=0;
			for(re int i=2;i<n;++i)pos[++num]=-a[i];
			sort(pos+1,pos+num+1);
			ans=-1e18;
			for(re int i=1;i<=num;++i){
				ans=max(ans,pos[i]*dlt+s);
				s-=(-pos[i])*a[n],s+=(-pos[i])*a[1];
				dlt-=a[n],dlt+=a[1];
			}
			printf("%lld\n",ans);
		}
	}
}