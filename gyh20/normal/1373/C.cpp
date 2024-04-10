#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
using namespace std;
int t,n,m,a[1000002],x;
char s[1000002];
long long ans;
signed main(){
	t=read();
	while(t--){
		scanf("%s",s+1);ans=0;
		n=strlen(s+1);
		for(re int i=1;i<=n;++i)if(s[i]=='+')a[i]=a[i-1]+1;else a[i]=a[i-1]-1;
		for(re int i=1;i<=n;++i)s[i]=min(s[i],s[i-1]);
		re int pos=1;
		for(re int i=0;i>=-n;--i){
			while(a[pos]>=i&&pos<=n)++pos;
			ans+=pos;
			if(pos>n){--ans;
			break;}
		}
		printf("%lld\n",ans);
	}
}