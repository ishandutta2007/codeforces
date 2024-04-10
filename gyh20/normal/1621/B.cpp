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
int t,n,m,a[1000002],ans,A,B,mn,mx,mn1,mn2,mn3;
signed main(){
	t=read();
	while(t--){
		n=read(),mn1=mn2=mn3=1e18,ans=2e9;mn=2e9,mx=0;
		for(re int i=1;i<=n;++i){
			re int x=read(),y=read(),z=read();
			if(x<mn)mn=x,mn1=mn3=1e15;
			if(y>mx)mx=y,mn2=mn3=1e18;
			if(x==mn)mn1=min(mn1,z);
			if(y==mx)mn2=min(mn2,z);
			if(x==mn&&y==mx)mn3=min(mn3,z);
			printf("%lld\n",min(mn1+mn2,mn3)); 
		}
	}
}