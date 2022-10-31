#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=105;typedef std::pair<int,int> pi;
bool f[N][N][N],used[N];char s[N];int c[N],a[N];std::vector<int> e[N];int d[N][N],S;
void dfs(int x,int fa){for(auto v:e[x])if(v!=fa)d[S][v]=d[S][x]+1,dfs(v,x);}
void MAIN(){
	int n;read(n);memset(used,0,n+3);
	for(int i=1;i<=n;++i)e[i].clear(),c[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			scanf("%s",s+1);
			for(int k=1;k<=n;++k){
				f[i][j][k]=f[j][i][k]=s[k]-'0';
				if(f[i][j][k])++c[k];
			}
		}
	}
	std::vector<pi> vec;
	for(int t=1;t<=n-2;++t){
		int mn=1e9,p=-1;
		for(int i=1;i<=n;++i)if(!used[i]&&c[i]<mn)mn=c[i],p=i;
		used[p]=1,a[t]=p;mn=1e9;int nd=-1;
		for(int i=1;i<=n;++i)if(!used[i]){
			bool flag=1;
			for(int x=1;x<=n;++x)if(!used[x])for(int y=x+1;y<=n;++y)if(!used[y])flag&=f[x][y][i]==f[x][y][p];
			bool tag=0;for(int x=1;x<=n;++x)if(!used[x])tag|=f[p][x][i];
			if(tag&&flag&&c[i]<mn)mn=c[i],nd=i;
		}
		if(nd==-1)return puts("No"),void();
		vec.pb({p,nd});
		for(int i=1;i<=n;++i)if(!used[i])for(int j=1;j<=n;++j)if(f[p][i][j])--c[j];
	}
	int x=-1,y=-1;for(int i=1;i<=n;++i)if(!used[i])(x==-1?x:y)=i;
	vec.pb({x,y});
	for(const auto &it:vec)e[it.first].pb(it.second),e[it.second].pb(it.first);
	for(int i=1;i<=n;++i)S=i,d[i][i]=0,dfs(i,0);
	bool flag=1;for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)for(int k=1;k<=n;++k)flag&=f[i][j][k]==(d[i][k]==d[j][k]);
	if(!flag)puts("No");
	else{
		puts("Yes");
		for(const auto &it:vec)printf("%d %d\n",it.first,it.second);
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}