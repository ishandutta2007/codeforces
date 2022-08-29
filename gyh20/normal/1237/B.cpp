#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[100002],pos,vis[100002],ans;
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	pos=1;
	for(re int i=1,x;i<=n;++i){
		while(vis[a[pos]])++pos;
		x=read();
		vis[x]=1;
		if(x!=a[pos])++ans;
	}
	printf("%d",ans);
}