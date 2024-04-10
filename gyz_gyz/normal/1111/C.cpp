#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 3000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,k,d[N],p[N],s[N][2];ll A,B;
ll f(int x){
	if(!x)return A;if(!d[x])return B*p[x];
	return min(B*(1<<d[x])*p[x],f(s[x][0])+f(s[x][1]));
}
int main(){
	scanf("%d%d%lld%lld",&n,&k,&A,&B);
	int m=1;d[1]=n;p[1]=k;
	rep(i,1,k){int t;
		scanf("%d",&t);--t;int x=1;
		dep(i,n-1,0){
			bool y=(t>>i)&1;
			if(!s[x][y])s[x][y]=++m,d[m]=d[x]-1;
			++p[x=s[x][y]];
		}
	}
	printf("%lld\n",f(1));
}