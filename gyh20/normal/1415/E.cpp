#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ss=1;
	while(y){
		if(y&1)ss=1ll*ss*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ss;
}
priority_queue<int>q;
int n,m,t,a[1000002],h[1000002];
long long ans,sum;
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1),reverse(a+1,a+n+1);
	for(re int i=1;i<=m+1;++i)q.push(0);
	for(re int i=1;i<=n;++i){
		int xx=q.top();
		q.pop();
		ans+=xx;
		xx+=a[i];
		q.push(xx);
	}
	printf("%lld",ans);
}