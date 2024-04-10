#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define re register
using namespace std;
typedef double db;
const db PI=acos(-1.0);
struct cp{db rl,im;};
struct Edge{
	int from,to,dist;
};
cp f[200002],g[200002];
Edge ed[200002];
int nc,ec,t,x;
int rev[200002];
db p[110][200002],dis[111][111],dp[111][40051],dp2[111][40051];
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline cp operator +(cp x,cp y){return (cp){x.rl+y.rl,x.im+y.im};}
inline cp operator -(cp x,cp y){return (cp){x.rl-y.rl,x.im-y.im};}
inline cp operator *(cp x,cp y){return (cp){x.rl*y.rl-x.im*y.im,x.rl*y.im+x.im*y.rl};}
inline cp operator /(cp x,db y){return (cp){x.rl/y,x.im/y};}
inline void FFT(cp *A,int cnt,int f){
	int cur=0;
	cp x,wi;
	for(re int i=0;i<cnt;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(re int i=2;i<=cnt;i<<=1){
		cur=i>>1,x=(cp){cos(2*PI/i),f*sin(2*PI/i)};
		for(re cp *p=A;p!=A+cnt;p+=i){
			wi=(cp){1,0};
			for(re int j=0;j<cur;++j){
				cp t=wi*p[j+cur],t2=p[j];
				p[j+cur]=t2-t,p[j]=t+t2;
				wi=wi*x;
			}
		}
	}
	if(f==-1)for(re int i=0;i<cnt;++i)A[i]=A[i]/cnt;
}
inline void calc(int l,int r){
	int mid=(l+r)>>1,cnt,lim;
	for(re int j=1;j<=ec;++j){
		cnt=1,lim=-1;
		while(cnt<=((r<<1)-l-mid-1))cnt<<=1,++lim;
		for(re int i=0;i<cnt;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lim),f[i]=g[i]=(cp){0,0};
		for(re int i=mid+1;i<=r;++i)f[i-mid-1].rl+=dp[ed[j].to][i];
		for(re int i=1;i<=r-l;++i)g[r-l-i].rl+=p[j][i];
		FFT(f,cnt,1),FFT(g,cnt,1);
		for(re int i=0;i<cnt;++i)f[i]=f[i]*g[i];
		FFT(f,cnt,-1);
		for(re int i=l;i<=mid;++i)dp2[j][i]+=f[i-mid-1+r-l].rl;
	}
}
inline void cdqFFT(int l,int r){ 
	if(l==r){
		for(re int i=1;i<=ec;++i)dp[ed[i].from][l]=min(dp[ed[i].from][l],dp2[i][l]+ed[i].dist);
		return;
	}
	int mid=(l+r)>>1;
	cdqFFT(mid+1,r),calc(l,r),cdqFFT(l,mid);
}
int main(){
	nc=read(),ec=read(),t=read(),x=read();
	for(re int i=1;i<=nc;++i)for(re int j=1;j<=nc;++j)dis[i][j]=i^j?1061109567.0:0;
	for(re int i=1;i<=ec;++i){
		ed[i].from=read(),ed[i].to=read(),ed[i].dist=read();
		dis[ed[i].from][ed[i].to]=min(dis[ed[i].from][ed[i].to],1.0*ed[i].dist);
		for(re int j=1;j<=t;++j)p[i][j]=read()/100000.0;
	}
	for(re int k=1;k<=nc;++k)for(re int i=1;i<=nc;++i)for(re int j=1;j<=nc;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(re int i=0;i<=(t<<1);++i)dp[nc][i]=i<=t?0:x;
	for(re int i=1;i<nc;++i)for(re int j=0;j<=(t<<1);++j)dp[i][j]=(j<=t)?0x3f3f3f3f:dis[i][nc]+x; 
	calc(1,t<<1),cdqFFT(0,t);
	printf("%.10lf\n",dp[1][0]);
}