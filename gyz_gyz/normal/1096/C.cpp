#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define P 998244353
#define G 3
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
void sol(){int n;
	scanf("%d",&n);
	rep(i,3,360)if(!(n*i%180)&&n*i/180<i-1){
		printf("%d\n",i);return;
	}
}
int main(){
	int T;scanf("%d",&T);
	rep(i,1,T)sol();
}