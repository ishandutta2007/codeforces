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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,a[1000002],b[1000002],ans,t,p0[1000002],p1[1000002];
char s[1000002];
inline int Abs(re int x){return x>0?x:-x;}
inline int work(re int* A,re int y){
	re int s=0;
	for(re int i=1;y<=n;y+=2,++i)s+=Abs(A[i]-y);
	return s;
}
signed main(){
	t=read();
	while(t--){
		n=read();
		re int s1=0,s0=0;p0[0]=p1[0]=0;
		for(re int i=1;i<=n;++i)a[i]=read()%2;
		for(re int i=1;i<=n;++i){
			if(a[i])p1[++p1[0]]=i;
			else p0[++p0[0]]=i; 
		}
		if(Abs(p1[0]-p0[0])>1)puts("-1");
		else if(n&1){
			if(p1[0]>p0[0])ans=work(p0,2);
			else ans=work(p0,1);
			printf("%lld\n",ans);
		}
		else ans=min(work(p0,2),work(p0,1)),printf("%lld\n",ans);
	}
}