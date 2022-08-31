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
int t,n,m,a[1002][1002],s[1002][1002];
inline int ask(re int l1,re int r1,re int l2,re int r2){
	return s[r1][r2]^s[l1-1][r2]^s[r1][l2-1]^s[l1-1][r1-1];
}
inline int solve(){
	re int ans=0;
	for(re int i=1;i<=n+n;i+=4){
		for(re int j=1;j<=n;++j){
			re int o=i+1-j;
			if(o>=1&&o<=n)ans^=a[j][o],++j;
		}
	}
	return ans;
}
int main(){
	t=read();
	while(t--){
		n=read();re int ss=0;
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=n;++j){
				a[i][j]=read(),s[i][j]=s[i-1][j]^s[i][j-1]^s[i-1][j-1]^a[i][j];
			}
		ss^=solve();
		for(re int i=1;i<=n;++i)reverse(a[i]+1,a[i]+n+1);
		ss^=solve();
		printf("%d\n",ss);
	}
}