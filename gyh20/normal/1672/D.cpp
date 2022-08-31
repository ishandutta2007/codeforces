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
int t,n,m,a[1000002],ans,A,B,p1,p2,b[1000002],c[1000002];
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),c[i]=0;
		for(re int i=1;i<=n;++i)b[i]=read();
		re int pos=n;ans=1;
		for(re int i=n;i;--i){
			while(a[pos]!=b[i]&&c[a[pos]])--c[a[pos]],--pos;
			if(a[pos]^b[i]){
				ans=0;
				break;
			}
			if(b[i]!=b[i-1])--pos;
			else{
			--pos;
			while(b[i]==b[i-1])++c[b[i]],--i;	
			}
		}
		puts(ans?"YES":"NO");
	}
}