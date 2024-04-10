#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,a[1000002],b[1000002],t,head[1000002],cnt,f[1000002],rd[1000002];
queue<int>q;
struct edge{int to,next;}e[1000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt,++rd[y];}
int main(){
//	freopen("a.out","w",stdout);
	t=read();
	while(t--){
		cnt=0;
		n=read();
		for(re int i=1;i<=n;++i)head[i]=f[i]=rd[i]=0;
		for(re int i=1;i<=n;++i){
			re int x=read();
			while(x--)add(i,read());
		}
		re int s=0;
		for(re int i=1;i<=n;++i)if(!rd[i])q.push(i),f[i]=1;
		while(!q.empty()){
			re int x=q.front();++s;q.pop();
			for(re int i=head[x];i;i=e[i].next){
				f[e[i].to]=max(f[e[i].to],f[x]+(x<e[i].to));
				if(!(--rd[e[i].to]))q.push(e[i].to);
			}
		}
		re int ans=0;
		for(re int i=1;i<=n;++i)ans=max(ans,f[i]);
		printf("%d\n",s==n?ans:-1);
	}
}