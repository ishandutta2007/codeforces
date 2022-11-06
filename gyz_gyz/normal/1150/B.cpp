#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=1e3;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
char a[N][N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(i,2,n-1)rep(j,2,n-1)
		if(a[i][j]=='.'&&a[i-1][j]=='.'&&a[i][j-1]=='.'&&a[i+1][j]=='.'&&a[i][j+1]=='.')
			a[i][j]=a[i-1][j]=a[i][j-1]=a[i+1][j]=a[i][j+1]='#';
	rep(i,1,n)rep(j,1,n)if(a[i][j]=='.')return printf("NO\n"),0;
	printf("YES\n");
}