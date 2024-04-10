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
int t,n,m,a[1000002],ans,cnt,head[1000002];
signed main(){
	t=read();
	while(t--){
		n=read();
		re int k1=read(),k2=read(),b1=n-k1,b2=n-k2;
		re int w=read(),b=read();
		w-=min(k1,k2),w-=(max(k1,k2)-min(k1,k2))/2;
		b-=min(b1,b2),b-=(max(b1,b2)-min(b1,b2))/2;
		if(w>0||b>0)puts("NO");
		else puts("YES");
		
	}
}