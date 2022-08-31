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
int t,n,m,a[600002],ans,b[600002],pos;
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=a[i+n]=read(),b[i]=b[i+n]=read();
		b[n+1]=b[1];a[n+1]=a[1];pos=0;re int mn=1e18,ans=0;
		for(re int i=1;i<=n*2-1;++i){
			if(b[i]>a[i+1])b[i]=a[i+1];
			if(b[i]<mn){
				mn=b[i];
				pos=i+1;
			}
		}
		for(re int i=pos;i<pos+n;++i){
			ans+=a[i];a[i+1]-=b[i];
		}
		printf("%lld\n",ans);
	}
}