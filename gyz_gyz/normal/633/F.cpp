#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000010
#define ll long long
#define inf 1000000000
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,tot,x,y,st[N],ed[N],nt[N],p[N],w[N],v[N];
ll ans,a[N][4],b[N][4],c[N][4],aa[4],bb[4],cc[4];
void lk(int x,int y){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;
}
void f(int x){v[x]=1;b[x][0]=w[x];
	for(int i=st[x];i;i=nt[i])if(!v[p[i]]){f(p[i]);
		if(x==1){
			x=1;
		}
		rep(j,0,2)aa[j]=a[x][j],bb[j]=b[x][j],cc[j]=c[x][j];
		rep(j,0,2)rep(k,0,2-j){
			if(k&&(aa[j]+a[p[i]][k]>a[x][j+k]))
				a[x][j+k]=aa[j]+a[p[i]][k];			
			if(k&&(cc[j]+a[p[i]][k]>c[x][j+k]))
				c[x][j+k]=cc[j]+a[p[i]][k];
			if((j+k<2)&&(bb[j]+b[p[i]][k]>a[x][j+k+1]))
				a[x][j+k+1]=bb[j]+b[p[i]][k];
			if(k&&(bb[j]+a[p[i]][k]>b[x][j+k]))
				b[x][j+k]=bb[j]+a[p[i]][k];
			if(cc[j]+w[x]+b[p[i]][k]>b[x][j+k])
				b[x][j+k]=cc[j]+w[x]+b[p[i]][k];
		}
	}
	rep(i,0,2)if(c[x][i]>a[x][i])a[x][i]=c[x][i];
	rep(i,0,1)if(b[x][i]>a[x][i+1])a[x][i+1]=b[x][i];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&w[i]);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		lk(x,y);lk(y,x);
	}
	f(1);rep(i,1,2)if(a[1][i]>ans)ans=a[1][i];
	printf("%I64d\n",ans);
}