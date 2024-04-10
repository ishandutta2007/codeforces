#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,a[1000002],tg[1000002];
char s[1000002];
vector<int>D[1000002];
long long ans;
signed main(){
	n=1e6;
	for(re int i=1;i<=n;++i)for(re int j=i;j<=n;j+=i)D[j].push_back(i);
	t=read();
	while(t--){
		n=read();scanf("%s",s+1);ans=0;
		for(re int i=1;i<=n;++i)tg[i]=0;
		for(re int i=1;i<=n;++i)
			if(s[i]=='0'){
				re int fst=0;
				for(auto z:D[i])if(!tg[z]){ans+=z;break;}
			}
			else for(auto z:D[i])tg[z]=1;printf("%lld\n",ans);
	}
}