#include<cstdio>
using namespace std;
typedef long long LL;
#define lg2(x)(31-__builtin_clz(x))
int M1=1004535809,M2=167772161;
char s[300002];
int b1,b2,p1[300002],p2[300002],n,m,i1[300002],i2[300002],head[300002],cnt,mx[300002],tp[300002],tl[300002],son[300002],len[300002],fa[300002],F[19][300002],dep[300002],idx,dfn[300002],*up[300002],*down[300002];
int st[20][600002];
inline int Inv(int a,int&md){
	int ret=1,b=md-2;
	for(;b;b>>=1,a=1ll*a*a%md)if(b&1)ret=1ll*ret*a%md;
	return ret;
}
struct edge{
	int to,nxt;
}e[600002];
struct data{
	int s1,s2,len;
	inline void push_front(char c){s1=(s1+1ll*c*p1[len])%M1,s2=(s2+1ll*c*p2[len++])%M2;}
	inline void push_back(char c){s1=(1ll*s1*b1+c)%M1,s2=(1ll*s2*b2+c)%M2,++len;}
	inline data operator + (const data&a)const{return(data){(1ll*s1*p1[a.len]+a.s1)%M1,(1ll*s2*p2[a.len]+a.s2)%M2,len+a.len};}
	inline bool operator == (const data&a)const{return s1==a.s1&&s2==a.s2&&len==a.len;}
}a[300002],b[300002];
void dfs(int x){
	st[0][dfn[x]=++idx]=x,mx[x]=dep[x],a[x]=a[fa[x]],b[x]=b[fa[x]];
	a[x].push_back(s[x]),b[x].push_front(s[x]);
	for(int i=head[x];i;i=e[i].nxt)
		if(!dep[e[i].to]){
			dep[e[i].to]=dep[fa[e[i].to]=F[0][e[i].to]=x]+1;
			dfs(e[i].to),st[0][++idx]=x;
			if(mx[e[i].to]>mx[x])mx[x]=mx[e[i].to],son[x]=e[i].to;
		}
}
void dfs2(int x){
	tl[tp[x]]=x,len[tp[x]]=dep[x]-dep[tp[x]]+1;
	if(son[x])tp[son[x]]=tp[x],dfs2(son[x]);
	for(int i=head[x];i;i=e[i].nxt)
	if(dep[e[i].to]>dep[x]&&e[i].to!=son[x])dfs2(tp[e[i].to]=e[i].to);
}
inline int kfa(int x,int k){
	if(dep[x]<=k)return 0;
	if(k==0)return x;
	int lg=lg2(k);
	x=F[lg][x],k-=1<<lg;
	if(!k)return x;
	int dlt=dep[x]-dep[tp[x]];
	if(dlt>=k)return down[tp[x]][dlt-k];
	return up[tp[x]][k-dlt];
}
inline int LCA(int x,int y){
	if(dfn[x]>dfn[y])x^=y^=x^=y;
	x=dfn[x],y=dfn[y];
	int lg=lg2(y-x+1),a=st[lg][x],b=st[lg][y-(1<<lg)+1];
	return(dep[a]<dep[b])?a:b;
}
inline int read(){
	int t=0;char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline data get(int u,int v){
	data&x=b[u],&y=b[v];
	return(data){1ll*(x.s1-y.s1+M1)*i1[y.len]%M1,1ll*(x.s2-y.s2+M2)*i2[y.len]%M2,x.len-y.len};
}
inline data get_(int u,int v){
	data&x=a[u],&y=a[v];
	return(data){(y.s1-1ll*x.s1*p1[y.len-x.len]%M1+M1)%M1,(y.s2-1ll*x.s2*p2[y.len-x.len]%M2+M2)%M2,y.len-x.len};
}
int main(){
	n=read();scanf("%s",s+1);
	b1=37,b2=131,p1[0]=p2[0]=i1[0]=i2[0]=1;
	for(int i=1;i<=n;++i)p1[i]=1ll*p1[i-1]*b1%M1,p2[i]=1ll*p2[i-1]*b2%M2;
	i1[1]=Inv(b1,M1),i2[1]=Inv(b2,M2);
	for(int i=2;i<=n;++i)i1[i]=1ll*i1[i-1]*i1[1]%M1,i2[i]=1ll*i2[i-1]*i2[1]%M2;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		e[++cnt]=(edge){v,head[u]},head[u]=cnt;
		e[++cnt]=(edge){u,head[v]},head[v]=cnt;
	}
	dfs(dep[1]=1),dfs2(tp[1]=1);
	for(int i=1;i<19;++i)for(int j=1;j<=n;++j)F[i][j]=F[i-1][F[i-1][j]];
	for(int i=1;i<=n;++i)
	if(tp[i]==i){
		int h=len[i];
		up[i]=new int[h+2],down[i]=new int[h+2],*up[i]=*down[i]=i;
		for(int j=1,nw=fa[i];j<=h&&nw;++j,nw=fa[nw])up[i][j]=nw;
		for(int j=1,nw=son[i];j<=h&&nw;++j,nw=son[nw])down[i][j]=nw;
	}
	for(int i=1;i<20;++i)
	for(int j=1;j<=2*n;++j){
		int x=st[i-1][j],y=st[i-1][j+(1<<i-1)];
		st[i][j]=(dep[x]<dep[y])?x:y;
	}
	m=read();
	while(m--){
		int u1=read(),v1=read(),u2=read(),v2=read(),L1=LCA(u1,v1),L2=LCA(u2,v2),D1=dep[u1]+dep[v1]-2*dep[L1]+1,D2=dep[u2]+dep[v2]-2*dep[L2]+1,l=1,r=D1<D2?D1:D2,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			data x=dep[u1]-mid+1>=dep[L1]?get(u1,kfa(u1,mid)):get(u1,L1)+get_(fa[L1],kfa(v1,D1-mid));
			data y=dep[u2]-mid+1>=dep[L2]?get(u2,kfa(u2,mid)):get(u2,L2)+get_(fa[L2],kfa(v2,D2-mid));
			if(x==y)l=(ans=mid)+1;else r=mid-1;
		}
		printf("%d\n",ans);
	}
}