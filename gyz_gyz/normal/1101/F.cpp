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
#define N 401
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N][N][N],d[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);ll ans=0;
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,n)rep(j,i,n)a[0][i][j]=d[j]-d[i];
	rep(i,1,n-2)rep(j,1,n-i-1){int x=j;
		rep(k,j+i+1,n){
			while(a[i-1][j][x]<d[k]-d[x])++x;
			a[i][j][k]=min(d[k]-d[x-1],a[i-1][j][x]);
		}
	}
	rep(i,1,m){int l,r,t;ll x;
		scanf("%d%d%lld%d",&l,&r,&x,&t);
		t=min(t,r-l-1);
		ans=max(ans,a[t][l][r]*x);
	}
	printf("%lld\n",ans);
}