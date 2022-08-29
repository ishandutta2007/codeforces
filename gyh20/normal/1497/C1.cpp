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
int t,n,m,a[100002],ans,cnt,head[1000002],b[1000002];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
		while(m>3){
			printf("1 ");
			--n,--m;
		}
		if(n&1){
			printf("1 %d %d\n",n>>1,n>>1);
		}
		else {
			re int pw=1;
			if(n%4==0){
				printf("%d %d %d\n",n/2,n/4,n/4);
				continue;
			}
			while(n%2==0)n>>=1,pw<<=1;
			printf("%d %d %d\n",pw,(n-1)*(pw>>1),(n-1)*(pw>>1));
		}
	}
}