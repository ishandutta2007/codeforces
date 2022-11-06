#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
void sol(){ll n,g,b;
	scanf("%lld%lld%lld",&n,&g,&b);
	ll l=n,r=n*(1+b),m=(l+r)>>1;
	for(;l<r;m=(l+r)>>1){
		ll gd=m/(g+b)*g+min(m%(g+b),g);
		if(gd*2>=n)r=m;else l=m+1;
	}
	printf("%lld\n",m);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}