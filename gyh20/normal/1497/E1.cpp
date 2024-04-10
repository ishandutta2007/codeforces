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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],p[1000002],st[22][200002],L[200002],f[200002];
bool vis[20002];
map<int,int>v;
inline int ask(re int l,re int r){
	re int tmp=L[r-l+1];
	return max(st[tmp][l],st[tmp][r-(1<<tmp)+1]);
}
signed main(){
	t=read();
	n=20000;
	for(re int i=2;i<=n;++i){
		if(!vis[i])p[++cnt]=i;
		for(re int j=i+i;j<=n;j+=i)vis[j]=1;
	}
	while(t--){
		n=read(),m=read(),ans=0;v.clear();L[0]=-1;
		for(re int i=1;i<=n;++i){
			L[i]=L[i>>1]+1;
			a[i]=read();
			for(re int j=1;j<=cnt&&p[j]*p[j]<=a[i];++j){
				while(a[i]%(p[j]*p[j])==0)a[i]/=(p[j]*p[j]);
			}
			if(v.count(a[i]))st[0][i]=v[a[i]];
			else st[0][i]=0;
			v[a[i]]=i;
		}
		for(re int i=1;i<=L[n];++i)for(re int j=1;j+(1<<i)-1<=n;++j)st[i][j]=max(st[i-1][j],st[i-1][j+(1<<i-1)]);
		for(re int i=1;i<=n;++i){
			if(ask(1,i)==0)f[i]=1;
			else{
				re int l=1,r=i,pos=0;
				while(l<=r){
					re int mid=l+r>>1;
					if(ask(mid,i)>=mid)pos=mid,l=mid+1;
					else r=mid-1;
				}
				f[i]=f[pos]+1;
			}
		}
		printf("%d\n",f[n]);
	}
}