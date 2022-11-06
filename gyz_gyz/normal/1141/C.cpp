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
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
ll a[N];bool v[N];
int main(){
	int n;ll m=0;
	scanf("%d",&n);
	rep(i,2,n){int x;
		scanf("%d",&x);
		a[i]=a[i-1]+x;
		m=min(m,a[i]);
	}
	rep(i,1,n){
		a[i]+=1-m;
		if(a[i]>n||v[a[i]])return printf("-1\n"),0;
		v[a[i]]=1;
	}
	rep(i,1,n)printf("%lld ",a[i]);
}