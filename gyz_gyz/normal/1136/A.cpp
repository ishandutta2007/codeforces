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
#define N 10010
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,k,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d%d",&x,&a[i]);
	}
	scanf("%d",&k);
	rep(i,1,n)if(k<=a[i])return printf("%d\n",n-i+1),0;
}