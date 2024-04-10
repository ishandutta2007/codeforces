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
#define N 100010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
tuple<int,int,int>a[N];int id[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n){get<2>(a[i])=i;
		scanf("%d%d",&get<0>(a[i]),&get<1>(a[i]));
	}
	sort(a+1,a+n+1);int r=get<1>(a[1]);
	rep(i,1,n)id[get<2>(a[i])]=i;
	rep(i,2,n){
		if(get<0>(a[i])>r){
			rep(j,1,n)printf("%d ",1+(id[j]>=i));
			printf("\n");return;
		}r=max(r,get<1>(a[i]));
	}
	printf("-1\n");
}
int main(){int T;
	for(scanf("%d",&T);T--;)sol();
}