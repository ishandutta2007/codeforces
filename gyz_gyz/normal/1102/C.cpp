#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 5010
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,x,y,tot;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	if(x>y)return printf("%d\n",n),0;
	rep(i,1,n){int w;
		scanf("%d",&w);
		if(w<=x)++tot;
	}
	printf("%d\n",tot-tot/2);
}