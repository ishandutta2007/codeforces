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
int n,m,t,a[1000002],b[1000002],f[2][1000002],stk[1000002],l[1000002],r[1000002],tp;
long long ans;
char s[1000002];
signed main(){
	n=read();
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i)if(s[i]=='1')f[0][i]=f[0][i-1]+1;
	for(re int i=n;i;--i)if(s[i]=='1')f[1][i]=f[1][i+1]+1;
	for(re int i=1;i<=n;++i){
		if(s[i]=='1'){
			re int j=i;
			while(s[j]=='1')++j;--j;
			re int pos=tp;
			for(re int k=i;k<j;++k){
				while(pos&&f[1][stk[pos]]<=k-i+1)--pos;
				if(pos)ans+=1ll*(k-i+1)*(i-stk[pos]);
				else ans+=1ll*(k-i+1)*i;
			}
			while(pos&&f[1][stk[pos]]<=j-i+1)--pos;
			l[i]=stk[pos];
			for(re int k=i;k<=j;++k){
				while(tp&&f[1][k]>=f[1][stk[tp]])--tp;
				stk[++tp]=k;
			}
			i=j+1;
		}
	}tp=0;
	for(re int i=n;i>=1;--i){
		if(s[i]=='1'){
			re int j=i;
			while(s[j]=='1')--j;++j;
			re int pos=tp;
			for(re int k=i;k>j;--k){
				while(pos&&f[0][stk[pos]]<i-k+1)--pos;
				if(pos)ans+=1ll*(i-k+1)*(stk[pos]-i);
				else ans+=1ll*(i-k+1)*(n-i+1);
			}
			while(pos&&f[0][stk[pos]]<i-j+1)--pos;
			r[j]=(pos?stk[pos]:n+1);
			for(re int k=i;k>=j;--k){
				while(tp&&f[0][k]>=f[0][stk[tp]])--tp;
				stk[++tp]=k;
			}
			i=j-1;
		}
	}
	for(re int i=1;i<=n;++i){
		if(s[i]=='1'){
			re int j=i;
			while(s[j]=='1')++j;--j;
			for(re int k=1;k<=j-i-1;++k)ans+=1ll*k*(j-i-1-k+1);
			ans+=1ll*(i-l[i])*(r[i]-j)*(j-i+1);
			i=j+1;
		}
	}
	printf("%lld",ans);
}