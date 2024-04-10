#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
std::vector<int> e[N],r[N],vec[N];int f[N];
struct node{int u,d;inline bool operator < (const node &o)const{return d>o.d;}};
std::priority_queue<node> q;
int main(){
	int n,m;read(n,m);
	for(int i=1,x,y;i<=m;++i)read(x,y),e[x].pb(y),r[y].pb(x);
	memset(f,63,sizeof(f)),f[n]=0,q.push({n,0});
	while(!q.empty()){
		node o=q.top();q.pop();if(f[o.u]!=o.d)continue;
		for(auto v:r[o.u]){
			vec[v].pb(f[o.u]);int tmp=SZ(e[v])-SZ(vec[v])+f[o.u]+1;
			if(tmp<f[v])f[v]=tmp,q.push({v,tmp});
		}
	}
	printf("%d\n",f[1]);
	return 0;
}