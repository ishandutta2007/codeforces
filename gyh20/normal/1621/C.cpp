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
int t,n,m,a[1000002],ans,A,B,v[10002],num,stk[10002],tp,p[1002];
char s[1000002];
inline int ask(re int x){
	printf("? %d\n",x);
	fflush(stdout);
	return read();
}
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)v[i]=0;
		for(re int i=1;i<=n;++i)
			if(!v[i]){
				int s=ask(i);v[s]=1;
				while(1){
					re int nw=ask(i);
					p[s]=nw;
					if(v[nw])break;
					v[nw]=1;s=nw;
				}
			}
		printf("! ");
		for(re int i=1;i<=n;++i)printf("%d ",p[i]);
		puts("");fflush(stdout);
	}
}