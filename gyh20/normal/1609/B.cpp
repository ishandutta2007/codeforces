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
int t,n,m,a[1000002],ans;
char s[1000002],c[3];
inline bool ck(re int x){
	return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(re int i=1;i+2<=n;++i)ans+=ck(i);
	while(m--){
		re int x=read();
		scanf("%s",c);
		for(re int i=max(1,x-2);i<=min(n-2,x);++i)ans-=ck(i);
		s[x]=c[0];
		for(re int i=max(1,x-2);i<=min(n-2,x);++i)ans+=ck(i);
		printf("%d\n",ans);
	}
}