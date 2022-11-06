#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,x,y,t,w;
int main(){
	scanf("%d",&n);scanf("%d",&x);w=1;
	rep(i,2,n){y=x;
		scanf("%d",&x);
		if((x^y)&1){
			if(w&1)++t;else if(t)w=0,--t;else w=1;
		}else w^=1;
	}
	if(w)++t;
	if(t>1)printf("NO\n");else printf("YES\n");
}