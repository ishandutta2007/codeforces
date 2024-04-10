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
void sol(){ll a,b,n;int ans=0;
	scanf("%lld%lld%lld",&a,&b,&n);
	if(a>b)swap(a,b);
	while(b<=n){
		++ans;a+=b;swap(a,b);
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}