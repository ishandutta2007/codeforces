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
int t,n,m,a[1000002],ans,A,B;
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=0;
		int k=read(),ia1=0,ia2=0;
		re long long sum1=0,sum2=0;
		for(re int i=1;i<=k;++i){
			a[i]=read();
			if(a[i]>=n+n)sum1+=a[i]/n,ia1|=a[i]>=n+n+n;
			if(a[i]>=m+m)sum2+=a[i]/m,ia2|=a[i]>=m+m+m;
		}
		if(sum1>=m&&m%2==0)ans=1;
		if(sum1>=m&&ia1)ans=1;
		if(sum2>=n&&n%2==0)ans=1;
		if(sum2>=n&&ia2)ans=1;
		puts(ans?"Yes":"No");
	}
}