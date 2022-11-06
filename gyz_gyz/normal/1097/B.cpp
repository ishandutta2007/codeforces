#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;bool a[20][400];
int main(){
	scanf("%d",&n);a[0][0]=1;
	rep(i,1,n){int x;
		scanf("%d",&x);
		rep(j,0,359)if(a[i-1][j])a[i][(j+x)%360]=a[i][(j+360-x)%360]=1;
	}
	if(a[n][0])printf("YES\n");else printf("NO\n");
}