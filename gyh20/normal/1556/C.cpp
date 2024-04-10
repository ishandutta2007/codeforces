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
	n=read();
	for(re int i=1;i<=n;++i){
		a[i]=read();
		if(i%2==0)ans+=min(a[i],a[i-1]);
	}
	for(re int i=1;i<=n;++i){
		if(i%2==1)continue;
		re int s0=0,s1=0;
		for(re int j=i;j<=n;++j){
			if(j&1)s1+=a[j];
			else{
				re int x=min(a[j],s1);
				s1-=x,s0+=a[j]-x;
			}
			if(j%2==0)continue;
			re int dd=a[i-1]-s0,dd1=a[j+1]-s1;
			if(dd>=0&&dd1>=0)ans+=min(dd+(s0>0),dd1+(s1>0));
		}
	}
	printf("%lld",ans);
}