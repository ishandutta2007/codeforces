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
int t,n,m,ans;
char a[100002],b[100002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		scanf("%s%s",a+1,b+1);
		reverse(a+1,a+n+1),reverse(b+1,b+m+1);
		re bool ia=1;
		for(re int i=1;i<m;++i)ia&=a[i]==b[i];
		re bool ia1=0;
		for(re int i=m;i<=n;++i)ia1|=a[i]==b[m];
		puts(ia&&ia1?"YES":"NO");
	}
}