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
	t=1;
	while(t--){
		n=read();
		re int l=1,r=n*2001,pos=0;
		while(l<=r){
			re int mid=l+r>>1;
			printf("? %d\n",mid);fflush(stdout);
			if(read()==1)pos=mid,r=mid-1;
			else l=mid+1;
		}
		assert(pos);
		ans=pos;
		for(re int i=1;i<=n;++i){
			re int dlt=(pos)/i;
			printf("? %d\n",dlt);fflush(stdout);
			re int x=read();
			if(x)
			ans=min(ans,x*dlt);
		}
		printf("! %d\n",ans);fflush(stdout);
	}
}