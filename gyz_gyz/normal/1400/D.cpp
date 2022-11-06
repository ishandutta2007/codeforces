#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e3+10;
const int inf=1e9;
const int mo=998244353;
int a[N],l[N][N],r[N][N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,0,n+1)rep(j,1,n)l[i][j]=r[i][j]=0;
	rep(i,1,n){
		scanf("%d",&a[i]);
		rep(j,1,n)l[i][j]=l[i-1][j]+(j==a[i]);
	}ll ans=0;
	dep(i,n,1)rep(j,1,n)r[i][j]=r[i+1][j]+(j==a[i]);
	rep(i,1,n)rep(j,i+1,n)ans+=l[i-1][a[j]]*r[j+1][a[i]];
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}