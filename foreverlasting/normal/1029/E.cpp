//2018.10.24 by ljz
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
const int N=2e5+10;
namespace MAIN{
	int n;
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
	int dep[N];
	int ans;
	void dfs(const res &x,const res &fax,const res &depx){
		dep[x]=depx;
		bool flag=0;
		for(res i=head[x];~i;i=edge[i].next){
			res tox=edge[i].to;
			if(tox==fax)continue;
			dfs(tox,x,depx+1);
			if(dep[tox]>2)flag=1,dep[x]=1,dep[fax]=2;
		}
		ans+=flag;
	}
	inline void MAIN(){
		memset(head,-1,sizeof(head));
		n=read();
		for(res i=1;i<n;i++){
			res u=read(),v=read();
			addedge(u,v);
		}
		dfs(1,0,0);
		printf("%d\n",ans);
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}