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
int t,n,m,a[102],ans,cnt,head[1000002],b[1000002];
signed main(){
	t=read();
	while(t--){
		memset(a,0,sizeof(a));
		n=read();
		for(re int i=1;i<=n;++i)++a[read()];
		for(re int i=1;i<=n;++i){
			for(re int j=0;j<=100;++j){
				if(a[j]){
					printf("%d ",j);
					--a[j];
				}
			}
		}
		puts("");
		
	}
}