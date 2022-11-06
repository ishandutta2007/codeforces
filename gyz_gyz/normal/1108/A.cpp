#include<bits/stdc++.h>
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
void sol(){int l1,r1,l2,r2;
	scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
	if(l1!=l2){printf("%d %d\n",l1,l2);return;}
	if(r1!=r2){printf("%d %d\n",r1,r2);return;}
	if(l1!=r2){printf("%d %d\n",l1,r2);return;}
	if(l1!=r2){printf("%d %d\n",r1,l2);return;}
}
int main(){int T;
	for(scanf("%d",&T);T--;)sol();
}