#include<bits/stdc++.h>
#define re register
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
int t,n,m,a[1000002],ans,A,B;
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=1;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=n-m+1;i<=n;++i)if(a[i]!=-1&&a[i]!=0)ans=0;
		if(ans==0){
			puts("0");
			continue;
		}
		for(re int i=n-m;i;--i)a[i+m]=a[i];
		for(re int i=m+1;i<=n;++i){
			if(a[i]==-1)ans=1ll*ans*i%M;
			else if(a[i]==0)ans=1ll*ans*(m+1)%M;
			else if(a[i]+m>i)ans=0;
		}
		for(re int i=1;i<=m;++i)ans=1ll*ans*i%M;
		printf("%d\n",ans);
	}
}