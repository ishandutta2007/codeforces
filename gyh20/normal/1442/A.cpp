#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[200002],t,ans;
const int M=998244353;
inline int ksm(re int x,re int y){
	re int ss=1;
	while(y){
		if(y&1)ss=1ll*ss*x%M;
		y>>=1,x=1ll*x*x%M; 
	}
	return ans;
} 
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		re int pos=1;a[n+1]=0;
		while(a[pos]>=a[pos+1]&&pos<=n)++pos;
		if(pos>=n){
			puts("YES");
		}
		else{
			re int mx=a[pos],ia=1,mn=0;
			for(re int i=n;i>pos+1;--i){
				if(a[i]<a[i-1]){
					if(a[i-1]-a[i]>mx)ia=0;
					else mx-=a[i-1]-a[i];
				}
			}
			puts(ia?"YES":"NO");
		}
	}
}