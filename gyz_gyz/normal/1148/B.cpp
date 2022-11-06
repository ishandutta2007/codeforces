#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
int a[N],b[N];
int main(){int n,m,ta,tb,k,ans=0;
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);
	if(n<=k||m<=k)return printf("-1\n"),0;
	rep(i,0,k){
		if(a[i+1]+ta>b[m-k+i])return printf("-1\n"),0;
		ans=max(ans,*(lower_bound(b+1,b+n+1,a[i+1]+ta)+k-i));
	}
	printf("%d\n",ans+tb);
}