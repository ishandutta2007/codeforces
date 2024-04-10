#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
struct mt{int n,m;ll a[100][100];
	mt(){memset(this,0,sizeof(mt));}
};
mt operator *(mt a,mt b){mt c;
	c.n=a.n;c.m=b.m;
	for(int i=0;i<c.n;++i)
		for(int j=0;j<c.m;++j)
			for(int k=0;k<a.m;++k)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mo;
	return c;
}
void qk(mt &r,mt x,ll y){
	for(;y;y>>=1){
		if(y&1)r=r*x;x=x*x;
	}
}
int main(){ll n;int m;
	scanf("%lld%d",&n,&m);
	mt a,b;a.n=a.m=b.m=m;b.n=1;
	rep(i,0,m-2)a.a[i+1][i]=1;
	a.a[m-1][m-1]=a.a[0][m-1]=1;b.a[0][m-1]=1;
	qk(b,a,n);printf("%lld\n",b.a[0][m-1]);
}