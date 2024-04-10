#include<bits/stdc++.h>
#define re register
using namespace std;
//#define int long long
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
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],b[1000002],head[1000002],cnt,A,B,C,D;
long double ans;
struct edge{int to,next;}e[2000002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
char s[1000002];
#define Y puts("YES");
#define N puts("NO");
signed main(){
	t=read();
	while(t--){
		re int k=read()<<1;
		n=m=0,ans=0;
		for(re int i=1;i<=k;++i){
			re int x=read(),y=read();
			if(x)a[++n]=x;
			else b[++m]=y;
		}
		sort(a+1,a+n+1),sort(b+1,b+m+1);
		for(re int i=1;i<=n;++i)ans+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
		printf("%.12Lf\n",ans);
	}
}