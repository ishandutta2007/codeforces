#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,a[1000002],ans,f[502][502],tg[502][502];
signed main(){
	t=read();
	while(t--){
		n=read(),memset(f,0,sizeof(f)),memset(tg,0,sizeof(tg));
		tg[1][1]=1,f[1][1]=1;
		puts("1");
		for(re int i=2;i<=n;++i){
			re int mx=0,mn=1e9;
			for(re int j=1;j<=i;++j){
				f[i][j]=f[i-1][j-1]+f[i-1][j]-f[i-2][j-1];
				mx=max(mx,f[i][j]),mn=min(mn,f[i][j]);
			}
			for(re int j=1;j<=i;++j)if(f[i][j]==mn)++f[i][j],tg[i][j]=1;
				for(re int j=1;j<=i;++j)printf("%d ",tg[i][j]);
				puts("");
		}
	}
}