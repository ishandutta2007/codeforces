#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int a[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){int x;
		scanf("%d",&x);a[i]-=x;
	}
	sort(a+1,a+n+1);int x=1;ll ans=0;
	dep(i,n,1){
		while(x<i&&a[x]+a[i]<=0)++x;
		if(x==i)break;
		ans+=i-x;
	}
	printf("%lld\n",ans);
}