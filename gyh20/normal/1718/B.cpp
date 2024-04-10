#include<bits/stdc++.h>
#define re register
#define int long long
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
int t,n,m,a[1000002],ans,A,B,f[1000002],g[1000002];
char s[1000002];
signed main(){
	t=read();
	f[1]=f[2]=1;
	for(re int i=3;i<=60;++i)f[i]=f[i-1]+f[i-2];
	g[1]=g[2]=1;
	for(re int i=3;i<=60;++i)g[i]=g[i-2]+f[i];
	while(t--){
		n=read(),m=0;
		priority_queue<int>Q;
		for(re int i=1,x;i<=n;++i)Q.push(x=read()),m+=x;
		re bool ia=1;
		re int pos=-1,sum=0;
		for(re int i=1;i<=60;++i){
			sum+=f[i];
			if(sum==m)pos=i;
		}
		if(pos==-1){
			puts("NO");
			continue;
		}
		int lst=-1;
		for(re int i=pos;i;--i){
			int x=Q.top();Q.pop();
			if(x==lst){
				if(!Q.size()){ia=0;break;}
				x=Q.top();Q.pop();Q.push(lst);
			}
			if(x>g[i]){ia=0;break;}
			if(x<f[i]){ia=0;break;}
			x-=f[i];if(x)Q.push(x),lst=x;else lst=-1;
		}
		puts(ia?"YES":"NO");
		
	}
}