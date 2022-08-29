#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,fa[202],t,a[202],ans[202];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){
	fa[root(x)]=root(y);
}
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),fa[i]=i;
		for(re int i=1;i<=n;++i)Merge(i,a[i]);
		for(re int i=1;i<n;++i)
			if(root(i)^root(i+1)){
				for(re int j=1;j<=n;++j)if(a[j]==i)a[j]=i+1;else if(a[j]==i+1)a[j]=i;
				Merge(i,i+1);
			}
		ans[1]=1;
		for(re int i=2;i<=n;++i)ans[i]=a[ans[i-1]];
		reverse(ans+1,ans+n+1);
		for(re int i=1;i<=n;++i)printf("%d ",ans[i]);puts("");
	}
}