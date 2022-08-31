#include<bits/stdc++.h>
#define re register
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
int t,n,m,ans,a[1000002],b[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read();ans=0;int tt=0;
		for(re int i=1;i<=m;++i)a[i]=read();
		sort(a+1,a+m+1);
		for(re int i=1;i<m;++i)b[i]=a[i+1]-a[i]-1;
		b[m]=n-a[m]+a[1]-1;
		sort(b+1,b+m+1);
		for(re int i=m;i;--i){
			if(b[i]==tt+1){
				++ans;
				break;
			}
			ans+=max(0,b[i]-tt-1),tt+=4;
		}
		printf("%d\n",n-ans);
	}
}