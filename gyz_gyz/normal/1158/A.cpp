#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int inf=1e9;
int a[N],b[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);
	ll ans=0;
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	rep(i,1,n)ans+=1ll*a[i]*m;
	if(b[1]<a[n]){
		printf("-1\n");return 0;
	}
	rep(i,2,m)if(b[i]>a[n])ans+=b[i]-a[n];
	if(b[1]>a[n])ans+=b[1]-a[n-1];
	printf("%lld\n",ans);
}