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
const int M=1e9+7;
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
int t,n,m,a[1000002],ans,cnt,head[1000002],f[1002][1002];
inline int gcd(re int x,re int y){return y?gcd(y,x%y):x;}
inline bool check(re int x){
	re int y=x,s=0;
	while(x)s+=x%10,x/=10;
	if(gcd(y,s)>1)return 1;
	return 0;
}
inline int calc(re int x,re int y){
//	printf("%lld %lld\n",x,y);
	if(y==1)return 1;
	if(x<1)return 1;
	if(~f[x][y])return f[x][y];
	re int s=0;
	add(s,calc(n-x,y-1)),add(s,calc(x-1,y));
	return f[x][y]=s;
}
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
	memset(f,-1,sizeof(f));
		
		printf("%lld\n",calc(n,m));
	}
}