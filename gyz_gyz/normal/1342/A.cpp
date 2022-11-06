#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const ll inf=1e18;
const int mo=998244353;
void sol(){
	ll x,y,a,b;
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	printf("%lld\n",abs(x-y)*a+min(x,y)*min(b,a*2));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}