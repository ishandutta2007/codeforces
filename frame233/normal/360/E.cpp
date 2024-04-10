#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=10005;typedef long long ll;
struct edge{int v,l,r;};
std::vector<edge> e[N];int s1,s2;bool op;
struct node{int u,tp;ll d;inline bool operator < (const node &o)const{return d>o.d;}};
std::priority_queue<node> q;ll dis[N][2];int U[105],L[105],R[105];
void dij(){
	memset(dis,63,sizeof(dis)),dis[s1][0]=dis[s2][1]=0,q.push({s1,0,0}),q.push({s2,1,0});
	while(!q.empty()){
		node x=q.top();q.pop();int o=x.tp;if(dis[x.u][o]!=x.d)continue;
		for(const auto &it:e[x.u]){
			int v=it.v,w=dis[x.u][0]<dis[x.u][1]||(op&&dis[x.u][0]==dis[x.u][1])?it.l:it.r;
			if(dis[v][o]>dis[x.u][o]+w)dis[v][o]=dis[x.u][o]+w,q.push({v,o,dis[v][o]});
		}
	}
}
int main(){
	int n,m,k,t;read(n,m,k,s1,s2,t);
	for(int i=1,x,y,z;i<=m;++i)read(x,y,z),e[x].pb({y,z,z});
	for(int i=1,x,y,l,r;i<=k;++i)read(x,y,l,r),e[x].pb({y,l,r}),U[i]=x,L[i]=l,R[i]=r;
	op=0,dij();if(dis[t][0]<dis[t][1])puts("WIN");else{op=1,dij();if(dis[t][0]>dis[t][1])return puts("LOSE"),0;else puts("DRAW");}
	for(int i=1;i<=k;++i)printf("%d%c",dis[U[i]][0]<dis[U[i]][1]||(op&&dis[U[i]][0]==dis[U[i]][1])?L[i]:R[i]," \n"[i==k]);
	return 0;
}