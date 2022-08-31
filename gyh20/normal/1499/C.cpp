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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],cnt,head[1000002],lst;
char s[200002];
signed main(){
	t=read();
	while(t--){
		n=read();
		re int A=0,B=0,s1=0,s2=0,n1=0,n2=0,m1=1e9,m2=1e9,ans=1e18;
		for(re int i=1;i<=n;++i){
			a[i]=read();
			if(i&1){
				s1+=a[i];
				++n1;
				m1=min(m1,a[i]);
			}
			else{
				s2+=a[i];
				++n2;
				m2=min(m2,a[i]);
			}
			if(i>=2){
				ans=min(ans,s1+s2+(n-n1)*m1+(n-n2)*m2);
			}
		}
		printf("%lld\n",ans);
	}
}