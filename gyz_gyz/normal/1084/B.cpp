#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll m;
int main(){
	scanf("%d%lld",&n,&m);m=-m;int t=inf;
	rep(i,1,n){int x;
		scanf("%d",&x);t=min(x,t);m+=x;
	}
	if(m<0)printf("-1\n");else printf("%lld\n",min(1ll*t,m/n));
}