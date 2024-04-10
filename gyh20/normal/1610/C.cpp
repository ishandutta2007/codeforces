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
int t,n,m,a[1000002],ans,b[1000002],num;
inline bool ck(re int x){
	re int s=0;
	for(re int i=1;i<=n&&s!=x;++i)
		if(b[i]>=s&&a[i]>=x-s-1)
			++s;
	return s>=x;
}
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),b[i]=read();
		re int l=1,r=n,pos=0;
		while(l<=r){
			re int mid=l+r>>1;
			if(ck(mid))pos=mid,l=mid+1;
			else r=mid-1; 
		}
		printf("%d\n",pos);
	}
}