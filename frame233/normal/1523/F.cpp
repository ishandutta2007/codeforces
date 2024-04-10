#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=15,M=105,MAXT=1000005,inf=0x3f3f3f3f;
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
int X1[N],Y1[N],X2[M],Y2[M],T[M],_X2[M],_Y2[M],_T[M],_t[M],dis[M][M],D[N][M],DIS[N][N],a[1<<14][N];
int f[1<<14][M],g[1<<14][M];
int main(){
	int n,m;read(n,m);
	for(int i=0;i<n;++i)read(X1[i],Y1[i]);
	for(int i=1;i<=m;++i)read(_X2[i],_Y2[i],_T[i]),_t[i]=i;
	std::sort(_t+1,_t+m+1,[&](int a,int b){return _T[a]<_T[b];});
	for(int i=1;i<=m;++i)X2[i]=_X2[_t[i]],Y2[i]=_Y2[_t[i]],T[i]=_T[_t[i]];
	for(int i=1;i<=m;++i)for(int j=1;j<=m;++j)dis[i][j]=abs(X2[i]-X2[j])+abs(Y2[i]-Y2[j]);
	for(int i=0;i<n;++i)for(int j=1;j<=m;++j)D[i][j]=abs(X2[j]-X1[i])+abs(Y2[j]-Y1[i]);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)DIS[i][j]=abs(X1[i]-X1[j])+abs(Y1[i]-Y1[j]);
	for(int st=0;st<1<<n;++st)for(int i=0;i<n;++i){
		a[st][i]=1e9;
		for(int j=0;j<n;++j)if(st>>j&1)chmin(a[st][i],DIS[i][j]);
	}
	memset(f,63,sizeof(f)),memset(g,-63,sizeof(g));
	for(int st=0;st<1<<n;++st){
		if(lowbit(st)==st)f[st][0]=0;
		for(int j=m-1;j>=0;--j)chmin(f[st][j],f[st][j+1]);
		for(int i=1;i<=m;++i){
			if(st==0)g[st][i]=1;
			for(int j=1;j<i;++j)if(dis[i][j]+T[j]<=T[i])chmax(g[st][i],g[st][j]+1);
			int l=0,r=m,mid,tar=-inf;
			for(int j=0;j<n;++j)if(st>>j&1)chmax(tar,T[i]-D[j][i]);
			while(l<r)mid=(l+r+1)>>1,f[st][mid]<=tar?l=mid:r=mid-1;
			if(f[st][l]<=tar)chmax(g[st][i],l+1);
			if(g[st][i]>=0){
				chmin(f[st][g[st][i]],T[i]);
				for(int j=0;j<n;++j)if(!(st>>j&1))chmin(f[st|(1<<j)][g[st][i]],T[i]+D[j][i]);
			}
		}
		for(int j=m-1;j>=0;--j)chmin(f[st][j],f[st][j+1]);
		for(int j=0;j<=m;++j)if(f[st][j]<inf)for(int k=0;k<n;++k)if(!(st>>k&1))chmin(f[st|(1<<k)][j],f[st][j]+a[st][k]);
	}
	int ans=0;for(int st=0;st<1<<n;++st)for(int i=1;i<=m;++i)chmax(ans,g[st][i]);
	printf("%d\n",ans);
	return 0;
}