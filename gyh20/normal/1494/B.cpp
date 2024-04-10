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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a,b,c,d;
inline bool check(re int A,re int B,re int C){
	if(A<0||C<0)return 0;
	if(B==n){
		if(A==0&&C==0)return 0;
		return 1;
	}
	return 1;
}
inline int calc(re int a,re int b,re int c,re int d){
		re bool ia=0;
		if(a==n)ia=check(b-1,c,d-1);
		else if(a==n-1)ia=check(b-1,c,d)|check(b,c,d-1);
		else ia=check(b,c,d);
		return ia;
	
}
signed main(){
	t=read();
	while(t--){
		n=read(),a=read(),b=read(),c=read(),d=read();
		re bool ia=0;
		for(re int i=0;i<=1;++i)
			for(re int j=0;j<=1;++j)
				for(re int k=0;k<=1;++k)
					for(re int l=0;l<=1;++l)
						ia|=(a-i-j<=n-2&&a-i-j>=0)&&(b-k-j<=n-2&&b-k-j>=0)&& (c-k-l<=n-2&&c-k-l>=0)&& (d-i-l<=n-2&&d-i-l>=0);
		puts(ia?"YES":"NO");
			
	}
}