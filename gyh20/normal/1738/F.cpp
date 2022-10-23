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
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp,d[1000002],p[1000002],fa[1000002],v[1000002],tot;
inline bool cmp(re int x,re int y){return d[x]>d[y];}
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read();tot=0;
		for(re int i=1;i<=n;++i)d[i]=read(),p[i]=i,fa[i]=i,v[i]=0;
		sort(p+1,p+n+1,cmp);
		for(re int i=1;i<=n;++i)if(!v[p[i]]){
			re int x=p[i];v[x]=1;
			for(re int j=1;j<=d[x];++j){
				printf("? %d\n",x);
				++tot;
				fflush(stdout);
				re int z=read(),oz=v[z];v[z]=1;
				if(root(z)==root(x))break;
				fa[root(z)]=root(x);
				if(oz)break;
			}
		}
		assert(tot<=n);
		printf("! ");
		for(re int i=1;i<=n;++i)printf("%d ",root(i));
		fflush(stdout);
		puts("");
	}
}