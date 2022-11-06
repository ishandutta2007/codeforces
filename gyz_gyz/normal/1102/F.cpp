#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 10010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[16][N],d[16][16],f[1<<16][16][16];
int main(){int n,m,ans=0;
	scanf("%d%d",&n,&m);int nn=(1<<n)-1;
	rep(i,0,n-1)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,0,n-1)rep(j,0,n-1)if(i!=j){d[i][j]=inf;
		rep(k,1,m)d[i][j]=min(d[i][j],abs(a[i][k]-a[j][k]));
	}
	rep(i,1,nn)if((i&(-i))==i)f[i][ctz(i)][ctz(i)]=inf;
	else rep(j,0,n-1)if(i&(1<<j)){int y=i;
		do{int k=y&(-y);y-=k;int x=i-k;k=ctz(k);
			if(j!=k){int z=x;
				do{int l=z&(-z);z-=l;l=ctz(l);
					f[i][j][k]=max(f[i][j][k],min(f[x][j][l],d[k][l]));
				}while(z);
			}
		}while(y);
	}
	rep(i,0,n-1)rep(j,0,n-1){int x=f[nn][i][j];
		rep(k,2,m)x=min(x,abs(a[i][k]-a[j][k-1]));
		ans=max(ans,x);
	}
	printf("%d\n",ans);
}