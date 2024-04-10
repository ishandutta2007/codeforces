#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=4005,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
char s[N][N],t[N][N];int v[N*2],fa[N*2],ss[N*2];std::vector<int> vec[N*2];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	if(n%2==0&&m%2==0){
		int ans=1;for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='?')add(ans,ans);
		printf("%d\n",ans);return 0;
	}
	if(m%2==0){
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)t[i][j]=s[i][j];
		memset(s,0,sizeof(s)),std::swap(n,m);
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)s[i][j]=t[j][i];
	}
	if(n%2==0){
		int ans=0;
		for(int t=0;t<2;++t){
			int res=1;
			for(int i=1;i<=n;++i){
				int c=0,all=0;
				for(int j=1;j<=m;++j){
					if(s[i][j]=='1')all^=1;
					if(s[i][j]=='?')++c;
				}
				if(all!=t&&c==0)res=0;
				for(int i=0;i<c-1;++i)add(res,res);
			}
			add(ans,res);
		}
		printf("%d\n",ans);return 0;
	}
	std::iota(fa+1,fa+n+m+1,1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]=='?'){
				int a=find(i),b=find(j+n);
				if(a==b)++ss[a];else fa[a]=b,ss[b]+=ss[a];
			}
			else if(s[i][j]=='1')v[i]^=1,v[j+n]^=1;
		}
	}
	for(int i=1;i<=n+m;++i)vec[find(i)].pb(i);
	int ans=0;
	for(int t=0;t<2;++t){
		int res=1;
		for(int i=1;i<=n+m;++i)if(fa[i]==i){
			int cc=ss[i],all=0;
			for(auto it:vec[i])all^=v[it];
			if(all!=t*SZ(vec[i])%2)res=0;
			for(int i=0;i<cc;++i)add(res,res);
		}
		add(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}