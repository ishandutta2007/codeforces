#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
} 
int n,m,t,a[100002],mx,ans;
inline int check(re int x){
	for(re int i=40;~i;--i){
		if(x&(1ll<<i))return i+1;
	}
}
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read()+1e9;
		mx=ans=0;
		for(re int i=1;i<=n;++i){
			if(a[i]>=mx)mx=a[i];
			else ans=max(ans,check(mx-a[i]));
		}
		printf("%lld\n",ans);
	}
}