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
struct node{int x,y;bool operator <(const node a)const{return x==a.x?y<a.y:x<a.x;};}p[100002];
int n,m,ans,t,zt,a[100002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n*m;++i)p[i].x=read(),p[i].y=i;
		sort(p+1,p+n*m+1);ans=0;
		for(re int i=1;i<=n;++i){
			for(re int j=(i-1)*m+1;j<=i*m;++j)
				for(re int k=(i-1)*m+1;k<j;++k)
					if(p[k].x!=p[j].x)ans+=(p[k].y<p[j].y);
		}
		printf("%d\n",ans);
	}
}