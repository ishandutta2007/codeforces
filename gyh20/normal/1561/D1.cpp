#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,f[4000002],M,ans,s,tg[4000002];
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int main(){
	s=1,n=read(),M=read(); 
	for(re int i=1;i<=n;++i){
		add(tg[i],tg[i-1]),f[i]=s;
		add(f[i],tg[i]);
		for(re int j=i+i,cnt=1;j<=n;j+=i,++cnt){
			add(tg[j],f[i]);
			if(j+cnt+1<=n)add(tg[j+cnt+1],M-f[i]);
		}
		if(i^1)add(s,f[i]);
	}
	printf("%d",f[n]);
}