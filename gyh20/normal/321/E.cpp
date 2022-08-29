#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,k,a[4002][4002],dp[4002],siz[4002],hd,tl;
struct node{int x,l,r;}q[4002];
inline int f(re int x,re int y){return dp[y]+((a[x][x]+a[y][y]-(a[x][y]<<1))>>1);}
inline int calc(re int x){
	q[hd=tl=1]=(node){0,1,n};
	for(re int i=1;i<=n;++i){
		while(hd<tl&&q[hd].r<i)++hd;
		dp[i]=f(i,q[hd].x)+x,siz[i]=siz[q[hd].x]+1;
		if(f(n,i)>=f(n,q[tl].x))continue;
		while(hd<tl&&f(q[tl].l,q[tl].x)>f(q[tl].l,i))--tl;
		re int l=q[tl].l,r=q[tl].r+1,mid;
		while(l<r)mid=l+r>>1,f(mid,i)<f(mid,q[tl].x)?r=mid:l=mid+1;
		q[tl].r=r-1,q[++tl]=(node){i,r,n};
	}
	return siz[n];
}
int main(){
	n=read();k=read();
	for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+read();
	re int l=0,r=a[n][n],mid;
	while(l<r)calc(mid=l+r>>1)>k?l=mid+1:r=mid;
	calc(r),printf("%d\n",dp[n]-r*k);
}