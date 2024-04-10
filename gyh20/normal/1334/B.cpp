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
int t,n,m,a[100002],ans;
signed main(){
	t=read();
	while(t--){
		n=read();m=read();long long sum=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);reverse(a+1,a+n+1);ans=0;
		for(re int i=1;i<=n;++i){
			sum+=a[i];
			if(sum<i*m)break;
			ans=i;
		}
		printf("%lld\n",ans);
	}
}