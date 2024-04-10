//2018.10.27 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=3e5+10;
namespace MAIN{
	struct E{
		int next,to;
		E() {}
		E(res next,res to):next(next),to(to) {}
	}edge[N<<1];
	int head[N],cnt;
	inline void addedge(const res &u,const res &v){
		edge[++cnt]=E(head[u],v),head[u]=cnt;
		edge[++cnt]=E(head[v],u),head[v]=cnt;
	}
	int fa[N],len[N];
	inline int find(res x){
		while(x!=fa[x])x=fa[x]=fa[fa[x]];
		return x;
	}
	int n,m,Q;
	int rt,dep[N];
	void dfs(const res &x,const res &fax){
		dep[x]=dep[fax]+1;
		if(dep[x]>dep[rt])rt=x;
		for(res i=head[x];~i;i=edge[i].next){
			res tox=edge[i].to;
			if(tox==fax)continue;
			dfs(tox,x);
		}
	}
	inline int calc(const res &x){
	    rt=0;
		dfs(x,0);
		res p=rt;
		dep[p]=0;
		rt=0;
		dfs(p,0);
		return dep[rt]-1;
	}
	inline void MAIN(){
		n=read(),m=read(),Q=read();
		for(res i=1;i<=n;i++)fa[i]=i,head[i]=-1;
		for(res i=1;i<=m;i++){
			res u=read(),v=read();
			addedge(u,v);
			res fu=find(u),fv=find(v);
			if(fu!=fv)fa[fu]=fv;
		}
		for(res i=1;i<=n;i++)if(find(i)==i)len[i]=calc(i);
		while(Q--){
			res opt=read();
			if(opt==1){
				res x=read();
				printf("%d\n",len[find(x)]);
			}
			else {
				res x=read(),y=read(),fx=find(x),fy=find(y);
				if(fx==fy)continue;
				fa[fx]=fy,len[fy]=_max((len[fx]+1)/2+(len[fy]+1)/2+1,_max(len[fx],len[fy]));
			}
		}
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}