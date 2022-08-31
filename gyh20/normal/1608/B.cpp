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
int t,n,m,a[1000002],ans,b[1000002],A,B;
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),A=read(),B=read();
		if(A-B>1||B-A>1){
			puts("-1");
			continue;
		}
		if(A+B>n-2){
			puts("-1");
			continue;
		}
		if(A>B){
			re int p1=1,p2=n;
			for(re int i=1;i<=B+1;++i){
				printf("%d %d ",p1,p2);
				++p1,--p2;
			}
			while(p2>=p1)printf("%d ",p2),--p2;
		}
		else if(A<B){
			re int p1=1,p2=n;
			for(re int i=1;i<=A+1;++i){
				printf("%d %d ",p2,p1);
				++p1,--p2;
			}
			while(p1<=p2)printf("%d ",p1),++p1;
		}
		else{
			re int p1=1,p2=n;
			for(re int i=1;i<=B;++i){
				printf("%d %d ",p2,p1);
				++p1,--p2;
			}
			while(p2>=p1)printf("%d ",p2),--p2;
		}
		puts("");
	}
}