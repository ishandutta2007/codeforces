#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,p[12],n;
int main(){
	t=read();
	while(t--){
		memset(p,0,sizeof(p)),n=read();
		for(re int i=1,x,y;i<=n;++i){
			y=read(),x=read();
			p[x]=max(p[x],y);
		}
		re int ans=0;
		for(re int i=1;i<=10;++i)if(p[i])ans+=p[i];else ans=-1e9;
		if(ans<0)puts("MOREPROBLEMS");
		else printf("%d\n",ans);
	}
}