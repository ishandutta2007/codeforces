#include<bits/stdc++.h>
using namespace std;
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

const int N=1011,M=N*N/2;
const int inf=0x3f3f3f3f;

struct Edg{
	int u,v,w,id;
	void read(){
		scanf("%d%d%d",&u,&v,&w);
	}
	bool operator<(const Edg&t)const{
		return w>t.w;
	}
} e[M];

int n,m;

int f[N],g[N];
inline int fa(int i){
	static int j;
	return f[i]==i?i:(j=fa(f[i]),g[i]^=g[f[i]],f[i]=j);
}
int Solve(int l,int r){
	for(int i=0;i<=n;++i){
		f[i]=i;
		g[i]=0;
	}
	for(int i=1;i<=m;++i){
		Edg&x=e[i];
		if(x.id>r||x.id<l)continue;
		int u=fa(x.u),v=fa(x.v);
		debug("%d %d %d %d %d\n",x.u,x.v,x.w,u,v);
		if(u==v){
			if(g[x.u]==g[x.v]){
				return x.w;
			}
		}else{
			f[v]=u,g[v]=g[x.u]^g[x.v]^1;
		}
	}
	debug("ok\n");
	return -1;
}

int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	int T;
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=m;++i){
		e[i].read();
		e[i].id=i;
	}
	sort(e+1,e+m+1);
	for(;T--;){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",Solve(l,r));
	}
}