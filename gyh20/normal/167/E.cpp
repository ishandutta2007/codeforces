#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,M,rd[602],cd[602],head[602],cnt,f[602],p[602],Q[602],hd,tl,tot,pos[602],num,a[602][602],Rd[602];
struct edge{int to,next;}e[100002];
inline void addd(re int x,re int y){++cd[x],++rd[y],++Rd[y],e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline int det(){
	re int o=1;
	for(re int i=1;i<=num;++i){
		if(!a[i][i]){
			for(re int j=i+1;j<=num;++j)if(a[j][i]){swap(a[j],a[i]);break;}
			o=M-o;if(!a[i][i])return 0;
		}
		re int iv=M-ksm(a[i][i],M-2);
		for(re int j=i+1;j<=num;++j){
			re int s=1ll*a[j][i]*iv%M;
			for(re int k=i;k<=num;++k)add(a[j][k],1ll*a[i][k]*s%M);
		}
	}
	for(re int i=1;i<=num;++i)o=1ll*o*a[i][i]%M;
	return o;
}
int main(){
	n=read(),m=read(),M=read(),hd=1;
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),addd(x,y);
	for(re int i=1;i<=n;++i)if(!rd[i])Q[++tl]=i;
	for(re int i=1;i<=n;++i)if(!cd[i])pos[i]=++num;num=0;
	while(hd<=tl){
		re int x=Q[hd++];p[++tot]=x;
		for(re int i=head[x];i;i=e[i].next)if(!--rd[e[i].to])Q[++tl]=e[i].to;
	}
	for(re int i=1;i<=n;++i)
		if(!Rd[i]){
			++num,memset(f,0,sizeof(f)),f[i]=1;
			for(re int j=1,x;j<=n;++j)if(f[x=p[j]])for(re int k=head[x];k;k=e[k].next)add(f[e[k].to],f[x]);
			for(re int j=1;j<=n;++j)a[num][pos[j]]=f[j];
		}
	printf("%d",det());
}