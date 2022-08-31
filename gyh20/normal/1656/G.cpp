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
int t,n,m,a[1000002],ans,B,bl[1000002],p[1000002],nn,b[1000002],p1[200002],p2[200002],fa[200002],vis[200002],A[200002],pos[200002];
char s[1000002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){
	fa[root(x)]=root(y);
}
map<int,int>V;
int main(){
	t=read();
	while(t--){
		n=read(),ans=0,V.clear();
		for(re int i=1;i<=n;++i)a[i]=read(),b[i]=a[i],vis[i]=0;nn=0;
		for(re int i=1;i<=n;++i){
			if(V.count(a[i]))bl[V[a[i]]]=i,bl[i]=V[a[i]],a[i]=a[V[b[i]]]=++nn,p1[nn]=i,p2[nn]=V[b[i]],V.erase(b[i]);
			else V[a[i]]=i;
		}
		if(V.size()>1){
			puts("NO");
			continue;
		}
		re int pp=0;
		for(re int i=1;i<=nn;++i)p[p1[i]]=i,p[p2[i]]=n-i+1;
		for(auto z:V)p[z.second]=n+1>>1,pp=z.second;
		for(re int i=1;i<=n;++i)fa[i]=i;
		for(re int i=1;i<=n;++i)Merge(i,p[i]);
		for(re int i=1;i<=nn;++i){
			if(root(p1[i])^root(p2[i])){
				swap(p[p1[i]],p[p2[i]]);
				Merge(p1[i],p2[i]);
			}
		}
		m=0;
		for(re int i=1;i<=nn;++i)
			if(!vis[root(p1[i])]){
				re int x=root(p1[i]);
				vis[x]=1,A[++m]=i;
			}
		for(re int i=1;i<m;++i){
			re int x=A[i],y=A[i+1];
			swap(p[p1[x]],p[p1[y]]),swap(p[p2[x]],p[p2[y]]);
		}
		if(pp==(n+1>>1)){
			re bool ia=0;
			for(re int i=1;i<=n;++i)
				if(i^pp&&b[i]==b[pp]&&root(i)^root(pp)){
					swap(p[i],p[pp]),Merge(p[i],p[pp]),ia=1;
					break;
				}
			if(!ia){
				puts("NO");
				continue;
			} 
		}
				for(re int i=1;i<=n;++i)fa[i]=i;
		for(re int i=1;i<=n;++i)Merge(i,p[i]);
		for(re int i=1;i<=nn;++i){
			if(root(p1[i])^root(p2[i])){
				swap(p[p1[i]],p[p2[i]]);
				Merge(p1[i],p2[i]);
			}
		}
				for(re int i=1;i<=n;++i)fa[i]=i;
		for(re int i=1;i<=n;++i)Merge(i,p[i]);
		for(re int i=1;i<=n;++i)assert(root(i)==root(1));
		for(re int i=1;i<=n;++i)pos[p[i]]=i;
		puts("YES");
		for(re int i=1;i<=n;++i)printf("%d ",pos[i]);
		puts("");
	}
}