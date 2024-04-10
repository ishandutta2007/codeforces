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
int t,n,m,ans,A,B,C,D;
char a[1000002],b[1000002];
inline int calc(re int x,re int y){
	return x/(y<<1)*y+max(0,x%(y<<1)-y+1);
}
int main(){
	t=read();
	while(t--){
		n=read(),scanf("%s%s",a+1,b+1);
		A=B=C=D=0;
		for(re int i=1;i<=n;++i){
			A+=(a[i]=='0')&&(b[i]=='0');
			B+=(a[i]=='0')&&(b[i]=='1');
			C+=(a[i]=='1')&&(b[i]=='0');
			D+=(a[i]=='1')&&(b[i]=='1');
		}
		ans=1e9;
		if(B==C)ans=min(ans,B+C);
		if(D==A+1)ans=min(ans,A+D);
		if(ans==1000000000)puts("-1");
		else printf("%d\n",ans);
		
	}
}