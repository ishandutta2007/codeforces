#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[200002],c[200002],tim,h[200002],ans,tot;
int v[200002];
inline bool check(re int x,re int y){
	for(re int i=1;i<=x;++i){
		re int tmp=i;
		re bool ia=1;
		for(re int j=1;j<=y;++j){
			if(c[h[tmp]]!=c[h[i]]){
				ia=0;
				break;
			}
			tmp+=x;
			tmp=(tmp-1)%tot+1;
		}
		if(ia)return 1;
	}
	return 0;
}
inline void dfs(re int x){
	tot=0;h[++tot]=x;v[x]=1;
	for(re int y=a[x];y!=x;y=a[y]){v[y]=1,h[++tot]=y;}
	re int k=sqrt(tot);
	for(re int i=1;i<=k;++i){
		if(tot%i==0){
		if(check(i,tot/i)){ans=min(ans,i);return;}
		if(check(tot/i,i)){
			ans=min(ans,tot/i);
			
		}	}
	}
}
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),v[i]=0;
		for(re int i=1;i<=n;++i)c[i]=read();
		ans=1e9;
		for(re int i=1;i<=n;++i){
		if(!v[i])dfs(i);}
		printf("%d\n",ans);
	}
}