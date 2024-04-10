#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=20005;
int dp[15][N][31],f[N][15],Log2[N],to[N],g[31],tmp[31];
inline int _max(int a,int b){return to[a]<to[b]?b:a;}
inline int ask(int l,int r){
	int k=Log2[r-l+1];
	return _max(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(to[i]),to[i]=std::min(to[i]+i,n),f[i][0]=i;
	for(int i=n;i>=1;--i)for(int j=1;j<15&&i+(1<<(j-1))<=n;++j)f[i][j]=_max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;++i)for(int j=0;j<=30;++j)dp[0][i][j]=std::min(to[i]+j,n);
	for(int t=1;t<15;++t)for(int i=1;i<=n;++i){
		for(int j=0;j<=30;++j)for(int k=0;j+k<=30;++k)chmax(dp[t][i][j+k],dp[t-1][ask(i,dp[t-1][i][j])][k]);
	}
	for(int l,r,lim;q--;){
		read(l,r,lim),std::fill(g,g+lim+1,l);
		if(l==r){puts("0");continue;}
		int ans=0;
		for(int t=14;t>=0;--t){
			memset(tmp,0,sizeof(tmp));
			for(int j=0;j<=lim;++j)for(int k=0;j+k<=lim;++k)chmax(tmp[j+k],dp[t][ask(l,g[j])][k]);
			if(tmp[lim]<r)ans+=1<<t,memcpy(g,tmp,sizeof(g));
		}
		printf("%d\n",ans+1);
	}
	return 0;
}