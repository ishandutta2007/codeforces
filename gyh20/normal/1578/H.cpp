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
int n,m,a[1000002],b[1000002],ans,t,sum[402][402],s0,mn,val[402];
char s[402][402];
int main(){
	int t=read();
	while(t--){
		n=read(),m=read(),ans=1e9;
		for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j)
				sum[i][j]=sum[i-1][j]+(s[i][j]=='1');
		for(re int l=1;l<=n;++l)
			for(re int r=l+4;r<=n;++r){
				mn=-1e9;
				for(re int i=1;i<=m;++i){
					val[i]=val[i-1]+(sum[r-1][i]-sum[l][i])+(s[l][i]=='0')+(s[r][i]=='0');
					s0=val[i-1];
					if(i>=4)mn=max(mn,val[i-3]-(r-l-1-sum[r-1][i-3]+sum[l][i-3]));
					if(i>=4)ans=min(ans,r-l-1-sum[r-1][i]+sum[l][i]+(s0-mn));
				}
			}
		printf("%d\n",ans);
	}
}