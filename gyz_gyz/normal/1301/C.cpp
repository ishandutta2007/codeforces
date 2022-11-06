#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=1e9+7;
ll cal(ll x){
	return x*(x+1)/2;
}
void sol(){ll n,m;
	scanf("%lld%lld",&n,&m);
	ll d=(n-m)/(m+1),r=(n-m)%(m+1);
	printf("%lld\n",cal(n)-cal(d+1)*r-cal(d)*(m+1-r));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}