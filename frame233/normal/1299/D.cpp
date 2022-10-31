#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=1000000007,S=374;typedef std::pair<int,int> pi;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
struct LB{
	int d[5];bool is;
	LB(){memset(d,0,sizeof(d)),is=0;}
	inline int H()const{return d[0]+d[1]*2+d[2]*8+d[3]*64+d[4]*1024;}
	void ins(int x){
		for(int i=4;i>=0;--i)if(x>>i&1){
			if(d[i])x^=d[i];
			else{
				for(int j=0;j<i;++j)if(x>>j&1)x^=d[j];
				for(int j=4;j>i;--j)if(d[j]>>i&1)d[j]^=x;
				d[i]=x;return;
			}
		}
		is=1;
	}
}A,B,vec[S];int to[32769],ID,trans[S][S];
inline LB merge(const LB &a,const LB &b){LB c(a);for(int i=4;i>=0;--i)if(b.d[i])c.ins(b.d[i]);return c;}
inline int get(const LB &a){return a.is?S:to[a.H()];}
void DFS(int dep,int cur){
	if(dep==-1){to[A.d[0]+A.d[1]*2+A.d[2]*8+A.d[3]*64+A.d[4]*1024]=ID,vec[ID++]=A;return;}
	A.d[dep]=0,DFS(dep-1,cur);
	if(!(cur>>dep&1)){
		for(int st=0;st<1<<dep;++st){
			int tmp=st|1<<dep;
			A.d[dep]=tmp,DFS(dep-1,cur|tmp);
		}
	}
}
std::vector<pi> e[N];
int dfn[N],id,dis[N];bool flag;
void dfs(int x,int fa){
	dfn[x]=++id;
	for(const auto &it:e[x]){
		int v=it.first,w=it.second;if(v==fa)continue;
		if(!dfn[v])dis[v]=dis[x]^w,dfs(v,x);
		else if(dfn[v]<dfn[x]){
			A.ins(dis[x]^dis[v]^w);
			if(v!=1)B.ins(dis[x]^dis[v]^w);
			else flag=1;
		}
	}
}
int f[S+1],g[S+1];
int main(){
	DFS(4,0);for(int i=0;i<S;++i)for(int j=i;j<S;++j)trans[i][j]=trans[j][i]=get(merge(vec[i],vec[j]));
	int n,m;read(n,m);
	for(int i=1,x,y,z;i<=m;++i)read(x,y,z),e[x].pb({y,z}),e[y].pb({x,z});
	dfn[1]=id=1,f[0]=1;
	for(const auto &it:e[1]){
		int v=it.first,w=it.second;if(dfn[v])continue;
		flag=0,A=LB(),B=LB(),dis[v]=w,dfs(v,1);
		memcpy(g,f,sizeof(g));
		if(!A.is){int a=get(A);for(int i=0;i<S;++i)if(f[i])add(g[trans[a][i]],f[i]);}
		if(flag&&!B.is){int b=get(B);for(int i=0;i<S;++i)if(f[i])add(g[trans[b][i]],2LL*f[i]%mod);}
		memcpy(f,g,sizeof(f));
	}
	int ans=0;for(int i=0;i<S;++i)add(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}