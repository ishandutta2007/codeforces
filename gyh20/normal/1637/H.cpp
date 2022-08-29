#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,c[500002],t,a[500002];
inline void add(re int x){for(;x<=n;x+=x&(-x))++c[x];}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
int main(){
	t=read();
	while(t--){
		n=read(),fill(c+1,c+n+1,0);
		re long long ans=0;
		for(re int i=1;i<=n;++i){
			re int x=read();
			a[i]=(x-1<<1)+1-i;
			add(x),ans+=i-ask(x);
		}
		sort(a+1,a+n+1);
		for(re int i=0;i<=n;++i)printf("%lld ",(ans+=a[i])-(1ll*i*(i-1)>>1));
		puts("");
	}
}