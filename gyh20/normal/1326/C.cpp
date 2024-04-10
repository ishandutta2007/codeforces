#include<bits/stdc++.h>
#define re register
#define int long long
#define M 998244353
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int n,a[200002],b[200002],mx,k,p,lst,ans,ans1;
signed main(){
	n=read();k=read();p=n-k+1;lst=0;ans=1;
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=1;i<=n;++i){
		if(b[i]>=p){
			if(lst)ans=1ll*ans*(i-lst)%M;
			ans1+=b[i];
			lst=i;
		}
	}
	printf("%lld %lld",ans1,ans);
}