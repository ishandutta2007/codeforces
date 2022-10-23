// LUOGU_RID: 90460140
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{
	int x,y;
}F[262144],G[262144],ans[262144];
inline node max(re node x,re node y){return x.x>y.x?x:y;}
inline void Upd(node x,node&y,node&z){
	if(x.y==y.y)y=max(y,x);
	else if(x.x>y.x)z=y,y=x;
	else z=max(z,x); 
}
int n,a[262144],fa[262144];
long long Ans;
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)Ans-=a[i]=read();++n;
	for(re int i=1;i<=n;++i)fa[i]=i;
	for(re int ii=1;ii<=18;++ii){
		for(re int i=0;i<262144;++i)F[i]=G[i]=ans[i]=(node){-1000000000,0};
		for(re int i=1;i<=n;++i)Upd((node){a[i],root(i)},F[a[i]],G[a[i]]);
		for(re int i=0;i<262144;++i)
			for(re int j=0;j<18;++j)
				if(!((i>>j)&1))
					Upd(F[i],F[i^(1<<j)],G[i^(1<<j)]),
					Upd(G[i],F[i^(1<<j)],G[i^(1<<j)]);
		for(re int i=1;i<=n;++i){
			node tmp=root(i)==F[262143^a[i]].y?G[262143^a[i]]:F[262143^a[i]];
			tmp.x+=a[i],ans[root(i)]=max(ans[root(i)],tmp);
		}
		for(re int i=1;i<=n;++i)if(root(i)==i&&ans[i].y&&root(i)^root(ans[i].y))fa[root(i)]=root(ans[i].y),Ans+=ans[i].x;
	}printf("%lld",Ans);
}