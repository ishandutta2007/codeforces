#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
ll cal(int n){
	n=min(n,31);ll r=0,x=1;
	rep(i,1,n)r+=x,x<<=2;
	return r;
}
void sol(){int n;ll k;
	scanf("%d%lld",&n,&k);ll l=0,r=0;
	rep(i,1,n){l+=(1<<i)-1;
		r+=(1<<i)-1+((1<<(i+1))-3)*cal(n-i);
		if(k<l){printf("NO\n");return;}
		if(k<=r){printf("YES %d\n",n-i);return;}
	}printf("NO\n");
}
int main(){int T;
	for(scanf("%d",&T);T;--T)sol();
}