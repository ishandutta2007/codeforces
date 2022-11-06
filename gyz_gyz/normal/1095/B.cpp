#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 300000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
int n,a1,a2,b1,b2,a[N];
int main(){
	scanf("%d",&n);b1=b2=inf;
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x>a1)a2=a1,a1=x;else a2=max(a2,x);
		if(x<b1)b2=b1,b1=x;else b2=min(b2,x);
	}
	printf("%d\n",min(a1-b2,a2-b1));
}