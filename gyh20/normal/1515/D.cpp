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
struct node{
	int x,y;
	bool operator <(const node a)const{return x==a.x?y>a.y:x>a.x;}
}p[100002];
priority_queue<node>q;
int n,ans[200002],m,k,t,s,o,oo;
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),k=read();s=o=oo=0;
		for(re int i=1;i<=n;++i)ans[i]=0;
		for(re int i=1;i<=m;++i)++ans[read()];
		for(re int i=1;i<=k;++i)--ans[read()];
		re int s1=0,s2=0,m1=0,m2=0;
		for(re int i=1;i<=n;++i){
			if(ans[i]>0)s1+=ans[i],m1+=ans[i]/2;
			else s2+=-ans[i],m2+=(-ans[i])/2;
			if(ans[i]<0)ans[i]=-ans[i];

		}
		if(s1>s2){
			re int x=s1-s2>>1;
			s+=s2+x+max(x-m1,0ll);
		}
		else{
			re int x=s2-s1>>1;
			s+=s1+x+max(x-m2,0ll);
		}
		printf("%lld\n",s);
	}
}