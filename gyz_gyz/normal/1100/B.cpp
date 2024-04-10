#include<cstdio>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N],b[N];
int main(){int n,m,nw=0;
	scanf("%d%d",&n,&m);b[0]=n;
	rep(i,1,m){int x;
		scanf("%d",&x);--b[a[x]];
		if(!b[a[x]]&&nw==a[x]){
			++nw;printf("1");
		}else printf("0");
		++b[++a[x]];
	}
}