#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll>pil;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
ll a[N];
int main(){int n;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		rep(j,0,19)if((x>>j)&1)++a[j];
	}
	rep(i,1,n){ll x=0;
		rep(j,0,19)if(a[j]>=i)x|=1<<j;
		ans+=x*x;
	}
	printf("%lld\n",ans);
}