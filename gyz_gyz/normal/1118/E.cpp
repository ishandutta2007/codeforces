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
#define N 200010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){int n,m;
	scanf("%d%d",&m,&n);
	if(m>1ll*n*(n-1))return printf("No\n"),0;
	printf("Yes\n");
	rep(i,1,n-1)rep(j,1,n){
		if((i-1)*n+j>m)return 0;
		printf("%d %d\n",j,(j+i-1)%n+1);
	}
}