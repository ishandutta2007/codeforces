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
int t,n,m,a[1000002],ans,A,B,sum[1000002];
char v[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;++i)v[read()]=1;
		for(re int i=1;i<=m;++i)sum[i]=sum[i-1]+v[i];
		re bool ia=1;
		for(re int i=1;i<=m;++i){
			re int nn=0;
			if(v[i])
			for(re int j=i;j<=m;j+=i){
				re int r=min(m,j+i-1);++nn;
				if(sum[r]-sum[j-1]){
					ia&=v[nn];
				}
			}
		}
		for(re int i=1;i<=m;++i)v[i]=sum[i]=0;
		puts(ia?"Yes":"No");
	}
}