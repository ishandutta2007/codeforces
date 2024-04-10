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
int n;ll a[N][N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)a[i][j]=abs(i-j)<2?0:Inf;
	rep(i,1,n)rep(j,i+1,n)rep(k,j+1,n)
		a[i][k]=min(a[i][k],a[i][j]+a[j][k]+1ll*i*j*k);
	printf("%lld\n",a[1][n]);
}