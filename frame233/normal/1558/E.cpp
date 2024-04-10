#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005;
typedef long long ll;
int a[N],b[N],n,Fa[N];
std::vector<int> e[N];
bool used[N],vis[N];ll c;
bool dfs(int x,int fa,ll cur){
	vis[x]=true,Fa[x]=fa;
	for(auto v:e[x])if(v!=fa){
		if(used[x]&&used[v])continue;
		if(!used[x]&&used[v]){
			for(int u=x;!used[u];u=Fa[u])used[u]=true,c+=b[u];
			return 1;
		}
		else if(!used[x]&&vis[v]){
			for(int u=x;!used[u];u=Fa[u])used[u]=true,c+=b[u];
			for(int u=v;!used[u];u=Fa[u])used[u]=true,c+=b[u];
			return 1;
		}
		else if(!vis[v]&&cur>a[v]&&dfs(v,x,cur+b[v]))return 1;
	}
	return 0;
}
bool check(int mid){
	memset(used,0,n+3),used[1]=1,c=mid;
	while(std::count(used+1,used+n+1,0)){
		memset(vis,0,n+3);
		bool flag=0;
		for(int i=1;i<=n;++i)if(used[i]&&dfs(i,0,c)){flag=1;break;}
		if(!flag)return 0;
	}
	return 1;
}
void MAIN(){
	int m;read(n,m);
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=2;i<=n;++i)read(a[i]);
	for(int i=2;i<=n;++i)read(b[i]);
	for(int i=1,x,y;i<=m;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	int l=0,r=1e9+1,mid=(l+r)>>1;while(l<r)mid=(l+r)>>1,check(mid)?r=mid:l=mid+1;
	printf("%d\n",l);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}