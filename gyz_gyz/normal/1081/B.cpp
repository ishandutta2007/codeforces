#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,tot,a[N],p[N],w[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		a[i]=n-a[i];++p[a[i]];
	}
	rep(i,1,n)if(p[a[i]]%a[i]){
		printf("Impossible\n");return 0;
	}printf("Possible\n");
	rep(i,1,n){
		if(!(p[a[i]]--%a[i]))w[a[i]]=++tot;
		printf("%d ",w[a[i]]);
	}
}