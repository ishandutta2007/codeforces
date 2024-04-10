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
int n,m,b[32],a[32],Ext;
inline int calc(re int x,re int y,re int z){
	int vv=Ext>=z?z:1e18;
	if(x<=y)return z-1;
	if((1ll<<x-y-1)>=z)return min(vv,calc(x-1,y,z)+1);
	Ext+=((1ll<<y-1)-1)*(1ll<<(x-y-1)),z-=1ll<<x-y-1;
	return min(vv,calc(x-1,y,z)+((1ll<<x-y-1)-1)+1);
}
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)b[i]=read();
	while(m--){
		re int o=read(),x=read()+1,y=read();
		if(o==1)b[x]=y;
		else{
			re int ans=0;
			for(re int i=1;i<=n;++i)a[i]=b[i];
			for(re int i=x;i;--i)y-=a[i];
			for(re int i=x+1;i<=n;++i)
				if(y>=(1ll<<i-x)){
					re int o=min(y/(1ll<<i-x),a[i]);
					a[i]-=o,a[x]+=o*(1ll<<i-x),y-=o*(1ll<<i-x),ans+=o*((1ll<<i-x)-1);
				}
			Ext=0;
			for(re int i=x;i>1;--i)Ext+=((1ll<<i-1)-1)*a[i];
			if(y<=0)printf("%lld\n",ans);
			else{
				re bool ia=0;
				for(re int i=x+1;i<=n;++i)if(a[i]&&((1ll<<i-1)+Ext>=y)){ia=1,ans+=calc(i,x,y);break;}
				if(!ia){
					if(Ext>=y){
						printf("%lld\n",y+ans);
						continue;
					}
					puts("-1");
					continue;
				}
				printf("%lld\n",ans);
			}
		}
	}
}