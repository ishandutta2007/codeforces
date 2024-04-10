#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=1000000007;
typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int X[57],Y[57],Z[57],tx[57],ty[57],px,py;
std::vector<std::pair<int,int>> e[57*2];
ll fac[N];
int a[57],b[57],p1,p2,m,id[57*2],f[1<<19],ans[57],C[1<<19],F[57],dfn[57*2],ID,pos,siz[57*2];
bool mark[57*2][57*2];
std::pair<int,int> E[57];int w[57];
void dfs1(int x,int fa){
	dfn[x]=++ID,(x<=px?a[++p1]=x:b[++p2]=x),siz[x]=1;
	for(auto [v,w]:e[x])if(v!=fa){
		if(!dfn[v])dfs1(v,x),mark[x][v]=true,siz[x]+=siz[v];
		else if(dfn[v]<dfn[x])E[pos]={x,v},::w[pos++]=w;
	}
}
bool tag[57];
int dp[57*2][57][2],tp[57][2];
int dfs2(int x){
	for(int i=0;i<=siz[x]/2;++i)dp[x][i][0]=dp[x][i][1]=0;
	dp[x][0][tag[x]]=1;int s=0;
	for(auto [v,w]:e[x])if(mark[x][v]){
		int tmp=dfs2(v);
		memset(tp,0,(s+tmp+2)<<3);
		for(int j=0;j<=s;++j)for(int k=0;k<=tmp;++k){
			add(tp[j+k][1],1ULL*dp[x][j][1]*(dp[v][k][0]+dp[v][k][1])%mod);
			add(tp[j+k+1][1],1ULL*dp[x][j][0]*dp[v][k][0]%mod*w%mod);
			add(tp[j+k][0],1ULL*dp[x][j][0]*(dp[v][k][0]+dp[v][k][1])%mod);
		}
		s+=tmp+1;if(!tp[s])--s;
		memcpy(dp[x],tp,(s+1)<<3);
	}
	return s;
}
int main(){
	for(int i=1;i<1<<19;++i)C[i]=C[i>>1]+(i&1);
	fac[0]=fac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod;
	int n,k;read(n,k);
	for(int i=1;i<=k;++i)read(X[i],Y[i],Z[i]),tx[++px]=X[i],ty[++py]=Y[i];
	std::sort(tx+1,tx+px+1),std::sort(ty+1,ty+py+1);
	px=std::unique(tx+1,tx+px+1)-tx-1,py=std::unique(ty+1,ty+py+1)-ty-1;
	for(int i=1;i<=k;++i){
		X[i]=std::lower_bound(tx+1,tx+px+1,X[i])-tx,Y[i]=std::lower_bound(ty+1,ty+py+1,Y[i])-ty;
		e[X[i]].pb({Y[i]+px,Z[i]-1}),e[Y[i]+px].pb({X[i],Z[i]-1});
	}
	F[0]=1;
	for(int i=1;i<=px+py;++i)if(!dfn[i]){
		pos=0,p1=p2=0,m=0,dfs1(i,0);
		for(int j=1;j<=p1;++j)m+=SZ(e[a[j]]);
		memset(ans,0,sizeof(ans));
		if(std::min(p1,p2)<=pos){
			if(p1>p2)std::swap(p1,p2),std::swap(a,b);
			int _=0;for(int i=1;i<=p1;++i)id[a[i]]=_++;
			memset(f,0,4<<_),f[0]=1;
			for(int i=1;i<=p2;++i)for(int st=(1<<_)-1;st>=0;--st)for(const auto &it:e[b[i]])if(!(st>>id[it.first]&1))add(f[st|1<<id[it.first]],1ULL*f[st]*it.second%mod);
			for(int st=0;st<1<<_;++st)add(ans[C[st]],f[st]);
			for(int i=px;i>=0;--i)for(int j=1;j<=_;++j)add(F[i+j],1LL*F[i]*ans[j]%mod);
		}
		else{
			int lim=std::min(p1,p2);
			for(int st=0;st<1<<pos;++st){
				for(int i=1;i<=p1;++i)tag[a[i]]=0;
				for(int i=1;i<=p2;++i)tag[b[i]]=0;
				int coef=1,cnt=0;
				for(int i=0;i<pos;++i)if(st>>i&1){
					if(tag[E[i].first]||tag[E[i].second])coef=0;
					tag[E[i].first]=tag[E[i].second]=true,coef=1LL*coef*::w[i]%mod,++cnt;
				}
				if(!coef)continue;
				dfs2(i);for(int j=0;j+cnt<=lim;++j)add(ans[j+cnt],1LL*coef*(dp[i][j][0]+dp[i][j][1])%mod);
			}
			for(int i=px;i>=0;--i)for(int j=1;j<=lim;++j)add(F[i+j],1LL*F[i]*ans[j]%mod);
		}
		
	}
	int res=0;for(int i=0;i<=px;++i)add(res,fac[n-i]*F[i]%mod);
	printf("%d\n",res);
	return 0;
}