#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
std::vector<int> e[N];int f[N],siz[N];
void dfs(int x,int fa){siz[x]=1;for(auto v:e[x])if(v!=fa)dfs(v,x),siz[x]+=siz[v];}
void MAIN(){
	int n;read(n);for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	memset(f,0,(n+3)<<2),f[1]=1;for(int i=1;i<n;++i)add(f[1],f[1]);
	dfs(1,0);
	for(int i=2;i<n;++i)if((n-1)%i==0){
		bool flag=1;for(int j=1;j<=n;++j)flag&=siz[j]%i==0||(siz[j]-1)%i==0;
		f[i]=flag;
	}
	for(int i=n-1;i>=1;--i)for(int j=i+i;j<n;j+=i)sub(f[i],f[j]);
	for(int i=1;i<=n;++i)printf("%d%c",f[i]," \n"[i==n]);
	for(int i=1;i<=n;++i)e[i].clear();
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}