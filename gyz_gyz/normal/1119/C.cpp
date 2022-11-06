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
#define N 1010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,a[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,1,n)rep(j,1,m){int x;
		scanf("%d",&x);a[i][j]^=x;
	}
	rep(i,1,n-1)rep(j,1,m-1)if(a[i][j]){
		a[i][j]^=1;a[i][j+1]^=1;a[i+1][j]^=1;a[i+1][j+1]^=1;
	}
	rep(i,1,n)if(a[i][m])return printf("No\n"),0;
	rep(i,1,m)if(a[n][i])return printf("No\n"),0;
	printf("Yes\n");
}