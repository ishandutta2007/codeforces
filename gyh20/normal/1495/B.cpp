#include<bits/stdc++.h>
#define re register
using namespace std;
//#define int long long
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],b[1000002],ans,head[1000002],cnt,A,B,C,D,f[1000002],rd[1000002],cd[1000002],mx,num;
bool vis[1000002];
struct edge{int to,next;}e[2000002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt,++rd[y],++cd[x];}
char s[1000002];
inline void dfs(re int x){
	if(vis[x])return;
	vis[x]=1,f[x]=1;
	for(re int i=head[x];i;i=e[i].next){
		dfs(e[i].to);
		f[x]=max(f[x],f[e[i].to]+1);
	}
}
#define Y puts("YES");
#define N puts("NO");
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		if(i>1&&a[i-1]<a[i])addd(i,i-1);
		if(i<n&&a[i+1]<a[i])addd(i,i+1);
	}
	for(re int i=1;i<=n;++i)if(!rd[i])dfs(i);
	for(re int i=1;i<=n;++i){
		if(f[i]>mx)mx=f[i],num=1;
		else if(f[i]==mx)++num;
	}
	if(num>1)return puts("0"),0;
	for(re int i=1;i<=n;++i)
		if(cd[i]==2&&f[i]==mx){
			re int xx=(f[i+1]-1)/2*2+1,yy=(f[i-1]-1)/2*2+1;
			if(xx>=f[i-1]||yy>=f[i+1])continue;++ans;
		}
	printf("%d",ans);
}