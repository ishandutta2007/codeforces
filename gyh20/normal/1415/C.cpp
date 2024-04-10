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
inline int ksm(re int x,re int y){
	re int ss=1;
	while(y){
		if(y&1)ss=1ll*ss*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ss;
}
int n,m,k,x,y,t,a[1000002],ans,f[1000002];
char s[100002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),k=read();
		scanf("%s",s+1);
		x=read(),y=read();
		for(re int i=n;i;--i){
			if(i+k>n)f[i]=0;
			else f[i]=f[i+k];
			if(s[i]=='0')f[i]+=x;
		}
		ans=2e9;
		for(re int i=m;i<=n;++i)ans=min(ans,f[i]+(i-m)*y);
		printf("%d\n",ans);
	}
}