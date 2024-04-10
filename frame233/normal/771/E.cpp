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
const int N=300005;typedef long long ll;typedef std::pair<int,int> pi;
ll s[3][N];int p[3][N],dp[N],f[N],g[N];
std::vector<pi> vec[N][2];
inline void upd(int x,int y,int v){
	chmax(dp[std::max(x,y)],v);
	if(x==y)chmax(dp[x],v);
	else if(x<y)vec[x][1].pb({y,v});
	else vec[y][0].pb({x,v});
}
void extend(int x,int y,int v){
	if(x==y)upd(p[2][x],p[2][y],v+1);
	else upd(std::max(x,y),std::max(x,y),v);
	if(x<=y)upd(p[0][x],y,v+1);
	if(x>=y)upd(x,p[1][y],v+1);
}
int main(){
	int n;read(n);
	for(int i=0;i<2;++i)for(int j=1;j<=n;++j)read(s[i][j]);
	for(int i=1;i<=n;++i)s[2][i]=s[0][i]+s[1][i];
	for(int i=0;i<3;++i)for(int j=1;j<=n;++j)s[i][j]+=s[i][j-1];
	for(int i=0;i<3;++i){
		std::map<ll,int> mp;p[i][n+1]=n+1;
		for(int j=n;j>=0;--j){
			auto it=mp.find(s[i][j]);
			p[i][j]=it==mp.end()?n+1:it->second,mp[s[i][j]]=j;
			p[i][j]=std::min(p[i][j],p[i][j+1]);
		}
	}
	dp[0]=0;
	for(int i=0;i<n;++i){
		extend(i,i,dp[i]);
		f[i]=n+1;for(const auto &it:vec[i][0])if(it.second==dp[i]+1)chmin(f[i],it.first);
		g[i]=n+1;for(const auto &it:vec[i][1])if(it.second==dp[i]+1)chmin(g[i],it.first);
		if(f[i]<=n)extend(f[i],i,dp[i]+1);
		if(g[i]<=n)extend(i,g[i],dp[i]+1);
	}
	printf("%d\n",*std::max_element(dp,dp+n+1));
	return 0;
}