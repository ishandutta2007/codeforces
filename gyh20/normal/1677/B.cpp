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
int t,n,m,a[1000002],sum[1000002],ans,A,B,ia[2000002],lst[1000002],nxt[1000002],tg[1000002];
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n*m;++i)sum[i]=0,ia[i]=tg[i]=0;
		scanf("%s",s+1);
		for(re int i=1;i<=n*m;++i){
			if(i>=m)ia[i]=ia[i-m];
			if(s[i]=='1'){
				if(!ia[i])++sum[i];
				ia[i]=1;
			}
		}
		for(re int i=1;i<=n*m;++i){
			if(s[i-1]=='1')lst[i]=i-1;
			else lst[i]=lst[i-1];
		}
		for(re int i=1;i<=n*m;++i)if(s[i]=='1'){
			re int x=lst[i];
			if(!lst[i]||lst[i]<=i-m)++sum[i];
			else{
				for(re int j=lst[i]+m;j<i+m;++j)++tg[j];
			}
		}
		for(re int i=1;i<=n*m;++i){
			sum[i]+=sum[i-1];
			if(i>=m)tg[i]+=tg[i-m];
		}
		for(re int i=1;i<=n*m;++i)printf("%d ",sum[i]+tg[i]);
		puts("");
	}
}