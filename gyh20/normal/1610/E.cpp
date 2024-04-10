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
int t,n,m,a[1000002],ans,R[1000002];
int main(){
	t=read();
	while(t--){
		n=read();ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		a[n+1]=0;
		for(re int i=n;i;--i){
			if(a[i]==a[i+1])R[i]=R[i+1];
			else R[i]=i;
		}
		for(re int i=1;i<=n;++i){
			re int pos=R[i]+1,s=pos-i+1;
			if(pos>n)--s;
			while(pos<=n){
				pos=(int)(lower_bound(a+1,a+n+1,a[pos]+a[pos]-a[i])-a);
				if(pos>n)break;
				++s;
			}
			ans=max(ans,s);
		}
		printf("%d\n",n-ans);
	}
}