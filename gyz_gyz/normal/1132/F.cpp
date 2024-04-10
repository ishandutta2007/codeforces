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
#define N 510
#define M 10000010
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,a[N][N];char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	rep(i,1,n)rep(j,i,n)
		a[i][j]=i==j?0:n;
	rep(i,1,n-1)rep(j,1,n-i)rep(k,j+1,i+j)
		a[j][j+i]=min(a[j][j+i],a[j][k-1]+a[k][j+i]+(s[j]!=s[k]));
	printf("%d\n",a[1][n]+1);
}