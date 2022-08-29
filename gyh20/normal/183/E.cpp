#include<bits/stdc++.h>
#define re register
#define ll long long
#define int long long
using namespace std;
inline ll read(){
	re ll t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m;
ll a[200002],b[200002],ans;
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=m/n;++i){
		for(re int j=1;j<=n;++j)b[j]=a[j];
		for(re int j=n-1;j;--j)b[j]=min(b[j],b[j+1]-i);
		re ll c=(1ll*(1+n*(i-1)+1)*i)>>1;
		if(c>b[1])continue;
		re ll ext=(m-n*i)*i,s=c-i,sum=0;
		for(re int j=1;j<=1;++j){s+=i;re ll dlt=min(ext,b[j]-s);s+=dlt,ext-=dlt,sum+=s;}
		ext=min(ext,1ll*m-n*i);
		for(re int j=2;j<=n;++j){s+=i;re ll dlt=min(ext,b[j]-s);s+=dlt,ext-=dlt,sum+=s;}
		ans=max(ans,sum);
	}printf("%lld",ans);
}