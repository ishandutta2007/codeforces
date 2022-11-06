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
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=5e5+10;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
int main(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);int r=k;
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x&&m&&r<k)++r,--m;
		else if(r)--r;else if(m)--m;else return printf("%d\n",i-1),0;
	}
	printf("%d\n",n);
}