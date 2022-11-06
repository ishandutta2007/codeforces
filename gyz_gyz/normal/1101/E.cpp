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
#define N 200010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){int n,s1=0,s2=0;
	scanf("%d\n",&n);
	rep(i,1,n){char c;int x,y;
		scanf("%c%d%d\n",&c,&x,&y);
		if(x>y)swap(x,y);
		if(c=='+'){
			s1=max(s1,x);s2=max(s2,y);
		}else printf("%s\n",s1<=x&&s2<=y?"YES":"NO");
	}
}