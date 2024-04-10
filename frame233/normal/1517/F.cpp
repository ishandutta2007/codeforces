#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=305,mod=998244353,inv2=(mod+1)/2;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
std::vector<int> e[N];
int f[N][N],g[N][N],r;
int tf[N],tg[N];
int dfs(int x,int fa){
	f[x][0]=1,g[x][0]=1;
	int len=0;
	for(auto v:e[x])if(v!=fa){
		int tmp=dfs(v,x);
		memset(tf,0,(std::max(len,tmp+1)+3)<<2),memset(tg,0,(std::max(len,tmp+1)+3)<<2);
		for(int i=0;i<=len;++i){
			for(int j=0;j<=tmp;++j){
				add(tf[std::min(i,j+1)],1ULL*f[x][i]*f[v][j]%mod);
				if(j+1+i<=r)add(tf[i],1ULL*f[x][i]*g[v][j]%mod),add(tf[j+1],1ULL*g[x][i]*f[v][j]%mod);
				add(tg[std::max(i,j+1)],1ULL*g[x][i]*g[v][j]%mod);
				if(j+1+i>r)add(tg[j+1],1ULL*f[x][i]*g[v][j]%mod),add(tg[i],1ULL*g[x][i]*f[v][j]%mod);
			}
		}
		len=std::max(len,tmp+1);
		memcpy(f[x],tf,(len+3)<<2),memcpy(g[x],tg,(len+3)<<2);
	}
	return len;
}
int main(){
	int n;read(n);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	int ans=0;
	for(r=1;r<=n;++r){
		memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
		dfs(1,0);
		for(int i=0;i<=n;++i)add(ans,f[1][i]);
	}
	add(ans,1);
	for(int i=1;i<=n;++i)ans=1ULL*ans*inv2%mod;
	printf("%d\n",(n-ans+mod)%mod);
	return 0;
}