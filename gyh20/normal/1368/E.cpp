#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,head[200002],cnt,m,c[200002];
struct edge{int to,next;}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),cnt=0;
		for(re int i=1;i<=n;++i)head[i]=c[i]=0;
		for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(max(x,y),min(x,y));
		for(re int i=1;i<=n;++i)for(re int j=head[i];j&&(c[i]^2);j=e[j].next)if(c[e[j].to]^2)c[i]=c[e[j].to]+1;
		vector<int>ans;
		for(re int i=1;i<=n;++i)if(c[i]==2)ans.push_back(i);printf("%d\n",ans.size());
		for(auto z:ans)printf("%d ",z);puts("");
	}
}