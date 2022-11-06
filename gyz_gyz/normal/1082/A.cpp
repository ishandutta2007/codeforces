#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 270000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int cal(int n,int x,int y,int d){
	if(!(abs(x-y)%d))return abs(x-y)/d;
	int p=-1,q=-1;
	if(y%d==1){p=0;
		if(x>1)p+=(x-2)/d+1;
		if(y>1)p+=(y-2)/d+1;
	}
	if(!((n-y)%d)){q=0;
		if(x<n)q+=(n-x-1)/d+1;
		if(y<n)q+=(n-y-1)/d+1;
	}
	if(~p){
		if(~q)return min(p,q);
		else return p;
	}else  return q;
}
int main(){int T;
	scanf("%d",&T);
	rep(i,1,T){int n,x,y,d;
		scanf("%d%d%d%d",&n,&x,&y,&d);
		printf("%d\n",cal(n,x,y,d));
	}
}